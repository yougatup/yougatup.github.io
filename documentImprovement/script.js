var currentPoint = -1;
var questionList = [];
var videoId = '5-ZFOhHQS68';
var subsInfo = [];
var subsFrequency = [];
var questionRects = [];
var clickedRect = -1;
var rightDivAppeared = true;
var subTitleMouseOver = false;
var myVideo = document.getElementById("myVideo");
var myCanvas;
var playTimeDiv = document.getElementById("playTime");
var playBtn = document.getElementById("playBtn");
var pauseBtn = document.getElementById("pauseBtn");

var focusPosition = {};

// Newton's first law of motion 2 : D1NubiWCpQg
var tag = document.createElement('script');

tag.src = "https://www.youtube.com/iframe_api";
var firstScriptTag = document.getElementsByTagName('script')[0];
firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);

// 3. This function creates an <iframe> (and YouTube player)
//    after the API code downloads.
var player;
var contextStack = [];

function questionType(index, time, question, answer) {
	return {
		index: index,
		time: time,
		question: question,
		answer: answer
	};
}

var currentRow = -1;

function fillMyRect(index, c1, c2) {
	var questionCtx = document.getElementById("questionBar");
	var questionC = questionCtx.getContext("2d");

	questionC.fillStyle = c1;

	questionC.fillRect(0, questionRects[index].y, questionC.canvas.width - questionRects[index].w, questionRects[index].h);

	questionC.fillStyle = c2;
	questionC.fillRect(questionRects[index].x, questionRects[index].y, questionRects[index].w, questionRects[index].h);

	strokeRedRect();
}

function focusRow(index, color) {
	if(focusPosition[color] != null && focusPosition[color] != -1 && focusPosition[color] != index) {
		var rowIdx = focusPosition[color];

		if(subsInfo[rowIdx].rect != clickedRect){
			fillMyRect(subsInfo[rowIdx].rect, "#DDD", "black");
			subsInfo[rowIdx].row.style.background = getGradientString(subsInfo[rowIdx].row.fillPercent, "#CCC", "red");
		}

		if(rowIdx > 1 && subsInfo[rowIdx-1].rect != clickedRect) {
			fillMyRect(subsInfo[rowIdx-1].rect, "#DDD", "black");
			subsInfo[rowIdx-1].row.style.background = getGradientString(subsInfo[rowIdx-1].row.fillPercent, "#CCC", "red");
		}

		if(rowIdx+1 < subsInfo.length && subsInfo[rowIdx+1].rect != clickedRect) {
			fillMyRect(subsInfo[rowIdx+1].rect, "#DDD", "black");
			subsInfo[rowIdx+1].row.style.background = getGradientString(subsInfo[rowIdx+1].row.fillPercent, "#CCC", "red");
		}
	}

	focusPosition[color] = index;

	if(focusPosition["orange"] != null && focusPosition["orange"] != -1 && focusPosition["orange"] != focusPosition["yellow"] && subsInfo[focusPosition["orange"]].rect != clickedRect) {
		var myIndex = focusPosition["orange"];

		if(subsInfo[myIndex].rect != clickedRect) {
			fillMyRect(subsInfo[myIndex].rect, "orange", "green");
			subsInfo[myIndex].row.style.background = getGradientString(subsInfo[myIndex].row.fillPercent, "orange", "green");
		}
	}

	if(focusPosition["yellow"] != null && focusPosition["yellow"] != -1) {
		var myIndex = focusPosition["yellow"];

		if(subsInfo[myIndex].rect != clickedRect) {
			fillMyRect(subsInfo[myIndex].rect, "yellow", "green");
			subsInfo[myIndex].row.style.background = getGradientString(subsInfo[myIndex].row.fillPercent, "yellow", "green");
		}
	}

}

function moveTimeline(percent) {
	var ctx = document.getElementById("progressBar");
	var c = ctx.getContext("2d");

	var progressBarWidth = percent * c.canvas.width / 100;

	c.fillStyle = "#FFFFFF";
	c.fillRect(0, 0, progressBarWidth, c.canvas.height);

	c.fillStyle = "#AAA";
	c.fillRect(progressBarWidth, 0, c.canvas.width, c.canvas.height);

	$('#playTime').html(printTime(getVideoCurrentTime() * 1000) + " / " + printTime(getVideoDuration() * 1000));

	var current = (getVideoDuration() * percent) * 10;
	var flag = false;

	for(var i=1;i<subsInfo.length;i++) {
		var rectIdx = subsInfo[i].rect;

		if(subsInfo[i].start <= current && current < subsInfo[i].end) {
			flag = true;
			focusRow(i, "orange");
		}
	}

	if(!flag) {
		focusRow(-1, "orange");
	}
}

function getVideoCurrentTime() {
	return player.currentTime;
}

function getVideoDuration() {
	return player.duration;
}

function videoSeekTo(position) {
	player.currentTime = position;
}

function plotQuestionBar(clickedIndex) {
	var max = 0;
	for(var i=0;i<subsFrequency.length;i++) {
		if(max < subsFrequency[i])
			max = subsFrequency[i];
	}

	var ctx = document.getElementById("questionBar");
	var c = ctx.getContext("2d");

	c.clearRect(0, 0, c.canvas.width, c.canvas.height);

	questionRects = [];

	for(var i=1;i<subsFrequency.length;i++) { // subsInfo starts from 1
		// plot rectangle in subsInfo[i].start ~ subsInfo[i].end

		var startPoint = (i-1)/subsFrequency.length * c.canvas.height;
		var endPoint = i/subsFrequency.length * c.canvas.height;
		var myHeight = (subsFrequency[i] / max) * c.canvas.width;

		var isClicked = false;

		if(clickedIndex != -1 && clickedIndex == i) {
			isClicked = true;
		}

		subsInfo[i].isClicked = isClicked;
		subsInfo[i].row.fillPercent = subsFrequency[i] / max * 100;

		questionRects.push( {
			x: (c.canvas.width - myHeight),
			y: startPoint, 
			w: myHeight, 
			h: endPoint - startPoint,
			i: i
		});

		subsInfo[i].rect = questionRects.length-1;
	}

	c.fillStyle = "#000000";

	for(var i=0;i<questionRects.length;i++) {
		if(subsInfo[questionRects[i].i].isClicked == true){
			c.fillStyle = "red";
		}
		else{
			c.fillStyle = "#000000";

			subsInfo[questionRects[i].i].row.style.backgroundImage = getGradientString(subsInfo[questionRects[i].i].row.fillPercent, "#CCC", "red");
		}

		fillMyRect(subsInfo[questionRects[i].i].rect, "#DDD", c.fillStyle);

		//captionLeave(subsInfo[questionRects[i].i].row);
	}

	if(focusPosition["orange"] != null && focusPosition["orange"] != -1 && focusPosition["orange"] != focusPosition["yellow"] && subsInfo[focusPosition["orange"]].rect != clickedRect) {
		var myPosition = focusPosition["orange"];

		fillMyRect(subsInfo[myPosition].rect, "orange", "green");
		subsInfo[myPosition].row.style.background = getGradientString(subsInfo[myPosition].row.fillPercent, "orange", "green");
	}

	if(focusPosition["yellow"] != null && focusPosition["yellow"] != -1) {
		var myPosition = focusPosition["yellow"];

		fillMyRect(subsInfo[myPosition].rect, "yellow", "green");
		subsInfo[myPosition].row.style.background = getGradientString(subsInfo[myPosition].row.fillPercent, "yellow", "green");
	}

	if(clickedRect != -1) {
		fillMyRect(clickedRect, "yellow", "red");
		subsInfo[questionRects[clickedRect].i].row.style.background = getGradientString(subsInfo[questionRects[clickedRect].i].row.fillPercent, "yellow", "green");
	}
}

function getGradientString(percent, c1, c2) {
	return getCssValuePrefix() + 'linear-gradient(0deg, '+c1+', '+c1+' '+(100 - percent) + '%, '+ c2 +' '+ (100 - percent) + '%)';
}

function getCssValuePrefix()
{
	var rtrnVal = '';//default to standard syntax
	var prefixes = ['-o-', '-ms-', '-moz-', '-webkit-'];

	// Create a temporary DOM object for testing
	var dom = document.createElement('div');

	for (var i = 0; i < prefixes.length; i++)
	{
		// Attempt to set the style
		dom.style.background = prefixes[i] + 'linear-gradient(#000000, #ffffff)';

		// Detect if the style was successfully set
		if (dom.style.background)
		{
			rtrnVal = prefixes[i];
		}
	}

	dom = null;
	delete dom;

	return rtrnVal;
}

function plotSingleQuestion(questionTime) {
	if(subsInfo.length == 0) {
		// there is no subtitle information on this video, 
		// so plot single line for each question

		var ctx = document.getElementById("questionBar");
		var c = ctx.getContext("2d");

		var playerTotalTime = getVideoDuration();
		var relativePosition = (questionTime / playerTotalTime) * 100;

		var drawPosition = relativePosition * c.canvas.width / 100;

		c.beginPath();
		c.moveTo(drawPosition, 0);
		c.lineTo(drawPosition, c.canvas.height);
		c.stroke();
	} else {
		// we have subtitle information.
		// maybe we need to re-draw the whole bar ?

	}
}

function resizeCanvas(elementId, width, height) {
	c = document.getElementById(elementId);
	c.setAttribute('width', width);
	c.setAttribute('height', height);
}

function updateQuestionHistogram(element) {
	for(var i=1;i<subsInfo.length;i++){
		if(subsInfo[i].start <= element.time && element.time < subsInfo[i].end){
			subsFrequency[i] = subsFrequency[i] + 1;
			break;
		}
	}
}

function getQuestionHistogram() {
	for(var j=0;j<subsInfo.length;j++)
		subsFrequency[j] = 0;

	for(var i=0;i<questionList.length;i++) 
		updateQuestionHistogram(questionList[i]);
}

function loadSubsInfoFromFirebase() {
	var subsInfoRef	= firebase.database().ref('subsInfo/' + videoId);

	subsInfoRef.once("value", function(snapshot) {
		var obj = snapshot.val()
		for (var key in obj) {
			if (obj.hasOwnProperty(key)) {
				$('#myTable tr:last').after(
				'<tr id="myRow' + obj[key].index + '"><td>'+ obj[key].statement + '</td></tr>'
				);

				var myRow = document.getElementById("myRow" + obj[key].index);
				subsInfo[obj[key].index] = {
					'start': obj[key].start,
					'end': obj[key].end,
					'statement': obj[key].statement,
					'isClicked': false,
					'rect': '', 
					'row': myRow,
				};
			}
		}

	getQuestionHistogram();
/*
	var questionBarWidth = $('#myTable').width();
	var questionBarHeight = $('#myTable').height();
	resizeCanvas('questionBar', questionBarWidth, questionBarHeight);
*/
	plotQuestionBar(-1);

	}, function (errorObject) {
		console.log("The read failed: " + errorObject.code);
	});
}

function readData() {
	var questionRef = firebase.database().ref('questions/' + videoId);

	questionRef.once("value", function(snapshot) {
		var obj = snapshot.val()
		for (var key in obj) {
			if (obj.hasOwnProperty(key)) {
				registerQuestion(obj[key].time, obj[key].question, false);
			}
		}
	}, function (errorObject) {
		console.log("The read failed: " + errorObject.code);
	});
}

function InitializeDB(){
	// Initialize Firebase
	var config = {
		apiKey: "AIzaSyCl2ihXRpdU0C708JxRPZo5_Qa3M3G613U",
		authDomain: "documentimprovement-ebf04.firebaseapp.com",
		databaseURL: "https://documentimprovement-ebf04.firebaseio.com",
		storageBucket: "documentimprovement-ebf04.appspot.com",
	};
	firebase.initializeApp(config);
}

function loadDataFromFirebase(){
	InitializeDB();
	toggleSignIn();
	readData();
}

function writeToDB(time, question, answer) {
	// A post entry.
	var postData = {
		'time': time,
		'question': question,
		'answer': answer
	};

	// Get a key for a new Post.
	var newPostKey = firebase.database().ref().child('questions/' + videoId).push().key;

	// Write the new post's data simultaneously in the posts list and the user's post list.
	var updates = {};
	updates['/questions/' + videoId + '/' + newPostKey] = postData;

	return firebase.database().ref().update(updates);
}

function toggleSignIn() {
	if (firebase.auth().currentUser) {
		// [START signout]
		firebase.auth().signOut();
		// [END signout]
	} else {
		// [START authanon]
		firebase.auth().signInAnonymously().catch(function(error) {
			// Handle Errors here.
			var errorCode = error.code;
			var errorMessage = error.message;
			// [START_EXCLUDE]
			if (errorCode === 'auth/operation-not-allowed') {
				alert('You must enable Anonymous auth in the Firebase Console.');
			} else {
				console.error(error);
			}
			// [END_EXCLUDE]
		});
		// [END authanon]
	}
	//document.getElementById('quickstart-sign-in').disabled = true;
}


// 5. The API calls this function when the player's state changes.
//    The function indicates that when playing a video (state=1),
//    the player should play for six seconds and then stop.

function onPlayerStateChange(event) {
	if (event.data == YT.PlayerState.PLAYING) {

	} else {
		//clearTimeout(mytimer);
		//	$('#progressBar').hide();
	}
}



function stopVideo() {
	player.stopVideo();
}

function barClick(index){
	if(index == -1) {
		for(var i=0;i<questionRects.length;i++) {
			subsInfo[questionRects[i].i].isClicked = false;
		}
	} else {
		for(var i=0;i<questionRects.length;i++) {
			if(i == index) subsInfo[questionRects[i].i].isClicked = true;
			else subsInfo[questionRects[i].i].isClicked = false;
		}
	}

	if(clickedRect != -1){
		fillMyRect(clickedRect, "#DDD", "black");
		subsInfo[questionRects[clickedRect].i].row.style.background = getGradientString(subsInfo[questionRects[clickedRect].i].row.fillPercent, "#CCC", "red");
	}

	clickedRect = index;

	fillMyRect(clickedRect, "yellow", "red");
	displayQuestions(questionRects[clickedRect].i);
	subsInfo[questionRects[clickedRect].i].row.style.background = getGradientString(subsInfo[questionRects[clickedRect].i].row.fillPercent, "yellow", "green");

	//$('#timeArea').html("My question was raised at " + printTime(subsInfo[questionRects[clickedRect].i].start) + " ~ " + printTime(subsInfo[questionRects[clickedRect].i].end));

}

function printTime(time) {
	time = time / 1000;

	var h = parseInt(time/60/60);
	time = time - h * 60 * 60;

	var m = parseInt(time/60);
	time = time - m * 60;

	s = parseInt(time);

	h = ("0" + h).slice(-2);
	m = ("0" + m).slice(-2);
	s = ("0" + s).slice(-2);

	if(h > 0) return h + ":" + m + ":" + s;
	else return m + ":" + s;
}


function questionBarMouseEffectSetting() {
	var ctx = document.getElementById("questionBar");
	var c = ctx.getContext("2d");
	var mouseIsDown;
	var mouseIsOver = false;

	function moveScroll(e, x, y) {
		var tableHeight = $("#myTable").height();
		var leftSecondHeight = $("#leftSecond").height();

		var heightRatio = leftSecondHeight / tableHeight;
		var rectHeight = $("#questionBar").height() * heightRatio;

		var scrollRatio = (y - rectHeight/2) / c.canvas.height;

		$("#leftSecond").scrollTop(Math.max(0, scrollRatio * tableHeight));
	}

	c.canvas.onmousemove = function(e) {
		if(mouseIsDown) {

			var rect = this.getBoundingClientRect();
			var x = e.clientX - rect.left;
			var y = e.clientY - rect.top;

			moveScroll(e, x, y);
		}
	}

	c.canvas.onmousedown = function(e) {
		mouseIsDown = true;

		var rect = this.getBoundingClientRect();
		var x = e.clientX - rect.left;
		var y = e.clientY - rect.top;

		moveScroll(e, x, y);
	}

	c.canvas.onmouseup = function(e) {
		mouseIsDown = false;
	}
}

function progressBarMouseEffectSetting() {
	var ctx = document.getElementById("progressBar");
	var c = ctx.getContext("2d");

	var questionBarCtx = document.getElementById("questionBar");
	var questionBarC = questionBarCtx.getContext("2d");

	var mouseIsDown;

	c.canvas.onmousedown = function(e) {
		mouseIsDown = true;
	}

	c.canvas.onmouseup = function(e) {
		var rect = this.getBoundingClientRect();
		var x = e.clientX - rect.left;
		var y = e.clientY - rect.top;

		if(mouseIsDown) mouseClick(e, x, y);

		mouseIsDown = false;

		function mouseClick(e, x, y) {
			var relativePosition = (x / c.canvas.width) * 100;

			moveTimeline(relativePosition);
			videoSeekTo(relativePosition/100 * getVideoDuration());
		}
	}
}

function loadVideo() {
	player = document.getElementById("myVideo");
}

function isNowPlaying() {
	return !player.paused;
}

function toggleVideoStatus() {
	if(isNowPlaying()) pauseVideo();
	else playVideo();
}

function playVideo() {
	player.play();
}

function pauseVideo() {
	player.pause();
}

function backToVideo() {
	var canvas = document.getElementById("myCanvas");

	canvas.style.display = "none";
	myVideo.style.display = "inline";
}

function annotateVideo() {
	pauseVideo();

	myVideo = document.getElementById("myVideo");

	myVideo.style.display = "none";
	myCanvas.style.display = "inline";

	var context = myCanvas.getContext('2d');
	var videoRatio = myVideo.videoHeight / myVideo.videoWidth;
	var canvasRatio = myCanvas.height / myCanvas.width;

	if(videoRatio < canvasRatio) {
		var adjust = (myCanvas.height - (videoRatio * myCanvas.width)) / 2;
		context.drawImage(myVideo, 0, adjust, myCanvas.width, videoRatio * myCanvas.width);
	} else {
		var adjust = (myCanvas.width - (1/videoRatio * myCanvas.height)) / 2;
		context.drawImage(myVideo, adjust, 0, 1/videoRatio * myCanvas.height, myCanvas.height);
	}

	myCanvas.style.backgroundImage = "url(" + myCanvas.toDataURL() + ")";


//	alert(canvas.toDataURL());

	//var Img = new Image();
	//Img.src = canvas.toDataURL();

	//$('#myCanvas').erase();
	$('#myCanvas').sketch({defaultColor: "#ff0"});
}

function downloadCanvas() {
}

function strokeRedRect() {
	var questionCtx = document.getElementById("questionBar");
	var questionC = questionCtx.getContext("2d");

	var tableHeight = $("#myTable").height();
	var leftSecondHeight = $("#leftSecond").height();
	var scrollTop = $("#leftSecond").scrollTop();

	var heightRatio = leftSecondHeight / tableHeight;
	var scrollRatio = scrollTop / tableHeight;

	var rectWidth = $("#questionBar").width();
	var rectHeight = $("#questionBar").height() * heightRatio;
	var rectYpos = $("#questionBar").height() * scrollRatio;

	questionC.strokeStyle= "red";
	questionC.lineWidth = 1;
	questionC.strokeRect(0, rectYpos, rectWidth, rectHeight);
}
function prepare() {
	//event.target.playVideo();
	clearQuestionBox();

	myCanvas = document.createElement('canvas');
	myCanvas.id     = "myCanvas";
	myCanvas.width = $('#leftFirst').width();
	myCanvas.height = $('#leftFirst').height();
	myCanvas.style.display = "none";

	$('#leftFirst').prepend(myCanvas);

	myVideo = document.getElementById('myVideo');
	//myVideo.setAttribute('crossOrigin', 'anonymous');

	/* ------ bind ctrl + l to submitting question -- */

	jQuery('#questionBox').bind('keydown', 'ctrl+l', submitBtnClicked);

	/* ------ Progress Bar Initialization ------ */

	var progressBarWidth = $('#progressBar').width();
	var progressBarHeight = $('#progressBar').height();

	var questionBarWidth = $('#questionBar').width();
	var questionBarHeight = $('#questionBar').height();

	resizeCanvas('progressBar', progressBarWidth, progressBarHeight);
	resizeCanvas('questionBar', questionBarWidth, questionBarHeight);

//	$('#progressBar').show();
	$('#questionBar').show();

	/* ------ Preparing for regular job ----- */

	setInterval(function() {
		var playerTotalTime = getVideoDuration();

		var playerCurrentTime = getVideoCurrentTime();

		var playerTimeDifference = (playerCurrentTime / playerTotalTime) * 100;

		moveTimeline(playerTimeDifference);
	}, 100);        

	/* --------- Initialize question list --------- */

	loadDataFromFirebase();

	/* --------- Initialize subtitle information ---- */

	loadSubsInfoFromFirebase();

	/* ----------Context stack initialize----------- */

	//contextStack.push($('#mySlider'));

	/* ---------- Subtitle initialization --------- */

	function scrollSubtitle() {
		var clickedIdx = getClickedIdx();
		plotQuestionBar(clickedIdx);

		strokeRedRect();
	}

	$("#leftSecond").scroll(scrollSubtitle);

	$('#submitBtn').click(function() {
		submitBtnClicked();
	});

	$('#myVideo').click(function() {
		toggleVideoStatus();
	});
	$('#appearBtn').click(function() {
		appearBtnClicked();
	});

	$('#disappearBtn').click(function() {
		disappearBtnClicked();
	});

	$('#playBtn').click(function() {
		playVideo();
	});

	$('#pauseBtn').click(function() {
		pauseVideo();
	});

	$('#annotateBtn').click(function() {
		annotateVideo();
	});

	$('#backVideoBtn').click(function() {
		backToVideo();
	});

	$('#downloadBtn').click(function() {
		downloadCanvas();
	});

	$('#leftSecond').on("mouseover", ".captionTable", function() {
		subTitleMouseOver = true;
	});

	$('#leftSecond').on("mouseleave", ".captionTable", function() {
		subTitleMouseOver = false;

		focusRow(-1, "yellow");
	});

	$('#leftSecond').on("mouseover", ".captionTable tr", function() {
		for(var i=1;i<subsInfo.length;i++) {
			if(subsInfo[i].row == this) {
				focusRow(i, "yellow");
			}
		}
	});

	$('#leftSecond').on("click", ".captionTable tr", function() {
		for(var i=1;i<subsInfo.length;i++) {
			if(subsInfo[i].row == this) {
				//focusRow(i, "orange");
				barClick(subsInfo[i].rect);
				break;
			}
		}
	});

	/* ------ Question div click event handling ------  */
/*
	$('#rightSecond').on("click", ".questionElement", function() {
		contextPush($(this));
	});*/

	/* ------ Question bar mouse move setting ----- */

	questionBarMouseEffectSetting();

	/* ------ play bar mouse move setting ------ */
	progressBarMouseEffectSetting();
}
$(document).ready(function() {
	/* ------ Submit button click event handling ------  */

	loadVideo();

	prepare();
});


/*
function contextPush(element) {
	if (contextStack.length == 1) {
		player.pauseVideo();
	}

	var topElement = contextStack[contextStack.length-1];

	topElement.hide();

	var text = element.text();

	var $newdiv = $('<div />',{
		'id': "stackElem" + contextStack.length,
		'text': text,
		'class': "stackElement",
	});

	contextStack.push($newdiv);

	$('#leftFirst').append($newdiv);
}
*/

/*
function popBtnClicked() {
	while(contextStack.length > 1) {
		var popElement = contextStack.pop();

		popElement.remove();

		contextStack[contextStack.length-1].show();
	}
}
*/

function submitBtnClicked() {
	var playerCurrentTime = Number(getVideoCurrentTime() * 1000);

	registerQuestion(playerCurrentTime, getQuestionStatement(), true);
	writeToDB(playerCurrentTime, getQuestionStatement(), '');
	clearQuestionBox();
}

function getQuestionStatement() {
	return $('#questionBox').val();
}

function clearQuestionBox() {
	$('#questionBox').val('');
}

function getClickedIdx() {
	for(var i=0;i<questionRects.length;i++) {
		if(subsInfo[questionRects[i].i].isClicked == true) {
			return questionRects[i].i;
		}
	}

	return -1;
}

function registerQuestion(time, statement, displayResult) {
	var idx = questionList.length;

	var newQuestion = questionType(idx, time, statement, '');

	var divString = 
		'<div id="question' + newQuestion.index + '" class="questionElement">' +
		'<div class="questionContents">' + 
		newQuestion.question +
		'</div>' +
		'<div>' +
		'<button id="expandBtn' + newQuestion.index + '" class="expandBtn"> expand </button>' +
		'<button id="likeBtn' + newQuestion.index + '" class="likeBtn"> like </button>' +
		'</div>' +
		'</div>';

	$('#rightSecond').html(divString + ($('#rightSecond').html()));

	var $newdiv = document.getElementById("question"+idx);
	$newdiv.style.display = 'none';

	questionList.push(newQuestion);

	if(displayResult) {
		updateQuestionHistogram(questionList[questionList.length-1]);

		var clickedIdx = getClickedIdx();

		plotQuestionBar(clickedIdx);
		displayQuestions(clickedIdx);
	}
}

function displayQuestions(subsIndex) {
	if(subsIndex != -1) {
		//$('#forDebugging').text("# of question : " + subsFrequency[subsIndex]);
		for(var i=0;i<questionList.length;i++) {
			var myDiv = document.getElementById("question"+questionList[i].index);
			if(subsInfo[subsIndex].start <= questionList[i].time && questionList[i].time < subsInfo[subsIndex].end) {
				myDiv.style.display = 'block';
			} else {
				myDiv.style.display = 'none';
			}
		}
	} else {
		for(var i=0;i<questionList.length;i++) {
			var myDiv = document.getElementById("question"+questionList[i].index);
			myDiv.style.display = 'none';
		}
	}
}

