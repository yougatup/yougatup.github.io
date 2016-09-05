var currentPoint = -1;
var questionList = [];
var videoId = '5-ZFOhHQS68';
var subsInfo = [];
var subsFrequency = [];
var questionRects = [];
var clickedRect;
var rightDivAppeared = true;

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

function moveTimeline(percent) {
	var ctx = document.getElementById("progressBar");
	var c = ctx.getContext("2d");

	var progressBarWidth = percent * c.canvas.width / 100;

	c.fillStyle = "#FFFFFF";
	c.fillRect(0, 0, progressBarWidth, c.canvas.height);

	c.fillStyle = "#AAA";
	c.fillRect(progressBarWidth, 0, c.canvas.width, c.canvas.height);

	var current = (player.getDuration() * percent) * 10;

	var questionCtx = document.getElementById("questionBar");
	var questionC = questionCtx.getContext("2d");

	for(var i=1;i<subsInfo.length;i++) {
		var rectIdx = subsInfo[i].rect;

		if(subsInfo[i].isClicked == true){
			questionC.fillStyle = "red";
		questionC.fillRect(questionRects[rectIdx].x, questionRects[rectIdx].y, questionRects[rectIdx].w, questionRects[rectIdx].h);
		}
		else if(subsInfo[i].start <= current && current < subsInfo[i].end) {
			questionC.fillStyle = "green";
			subsInfo[i].row.style.background = "yellow";
			questionC.fillRect(questionRects[rectIdx].x, questionRects[rectIdx].y, questionRects[rectIdx].w, questionRects[rectIdx].h);
		} else {
			//questionC.fillStyle = "black";
			subsInfo[i].row.style.background = "#CCC";
		}

	}
}

function plotQuestionBar(clickedIndex) {
	/*
	// straight-forward way !
	for(var i=0;i<questionList.length;i++){
	plotSingleQuestion(questionList[i].time);
	}*/

	var max = 0;
	for(var i=0;i<subsFrequency.length;i++) {
		if(max < subsFrequency[i])
			max = subsFrequency[i];
	}

	var ctx = document.getElementById("questionBar");
	var c = ctx.getContext("2d");

	c.clearRect(0, 0, c.canvas.width, c.canvas.height);

	clickedRects = {
		x: -1,
		y: -1,
		w: -1,
		h: -1
	};

	questionRects = [];

	for(var i=1;i<subsFrequency.length;i++) { // subsInfo starts from 1
		// plot rectangle in subsInfo[i].start ~ subsInfo[i].end

		var startPoint = ((subsInfo[i].start/1000) / player.getDuration()) * c.canvas.width;
		var endPoint = ((subsInfo[i].end/1000) / player.getDuration()) * c.canvas.width;
		var myHeight = (subsFrequency[i] / max) * c.canvas.height;

		var isClicked = false;

		if(clickedIndex != -1 && clickedIndex == i) {
			isClicked = true;
		}

		subsInfo[i].isClicked = isClicked;

		questionRects.push( {
			x: startPoint, 
			y: (c.canvas.height - myHeight), 
			w: endPoint - startPoint, 
			h: myHeight,
			i: i
		});

		subsInfo[i].rect = questionRects.length-1;;
	}

	c.fillStyle = "#000000";

	for(var i=0;i<questionRects.length;i++) {
		if(subsInfo[questionRects[i].i].isClicked == true) c.fillStyle = "red";
		else c.fillStyle = "#000000";

		c.fillRect(questionRects[i].x, questionRects[i].y, questionRects[i].w, questionRects[i].h);
	}
}

function plotSingleQuestion(questionTime) {
	if(subsInfo.length == 0) {
		// there is no subtitle information on this video, 
		// so plot single line for each question

		var ctx = document.getElementById("questionBar");
		var c = ctx.getContext("2d");

		var playerTotalTime = player.getDuration();
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



function onYouTubeIframeAPIReady() {
	player = new YT.Player('mySlider', {
		height: '540',
		   width: '960',
		   videoId: videoId,
		   playerVars: {
			   'modestbranding' : 1,
		   'rel' : 0,
		   'showinfo' : 0
		   },
		   events: {
					   'onReady': onPlayerReady,
		   'onStateChange': onPlayerStateChange
				   }
	});
}

function resizeCanvas(elementId, width, height) {
	c = document.getElementById(elementId);
	c.setAttribute('width', width);
	c.setAttribute('height', height);
}

// 4. The API will call this function when the video player is ready.
function onPlayerReady(event) {
	//event.target.playVideo();
	clearQuestionBox();

	/* ------ bind ctrl + l to submitting question -- */

	jQuery('#questionBox').bind('keydown', 'ctrl+l', submitBtnClicked);

	/* ------ Progress Bar Initialization ------ */

	var progressBarWidth = $('#progressBar').width();
	var progressBarHeight = $('#progressBar').height();

	var questionBarWidth = $('#questionBar').width();
	var questionBarHeight = $('#questionBar').height();

	resizeCanvas('progressBar', progressBarWidth, progressBarHeight);
	resizeCanvas('questionBar', questionBarWidth, questionBarHeight);

	$('#progressBar').show();
	$('#questionBar').show();

	/* ------ Preparing for regular job ----- */

	var playerTotalTime = player.getDuration();

	setInterval(function() {
		var playerCurrentTime = player.getCurrentTime();

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

function questionBarMouseEffectSetting() {
	var ctx = document.getElementById("questionBar");
	var c = ctx.getContext("2d");
	var mouseIsDown;
	var mouseIsOver = false;

	function checkcolor(e) {
		var rect = c.canvas.getBoundingClientRect();
		var x = e.clientX - rect.left;
		var y = e.clientY - rect.top;
		var selectedIdx = -1;
		var current = Number(player.getCurrentTime() * 1000);

		c.clearRect(0, 0, c.canvas.width, c.canvas.height);

		for(var i=0;i<questionRects.length;i++) {
			var r = questionRects[i];

			c.beginPath();
			c.rect(r.x, 0, r.w, c.canvas.height);

			if(rightDivAppeared && (subsInfo[r.i].isClicked == true || c.isPointInPath(x, y))) {
				if(selectedIdx == -1 && subsInfo[r.i].isClicked == true) {
					selectedIdx = r.i;
					c.fillStyle = "red";
				} else {
					c.fillStyle = "green";
					//subsInfo[r.i].row.style.background = "yellow";
				}
			} else if(subsInfo[r.i].start <= current && current < subsInfo[r.i].end) {
				c.fillStyle = "green";
					subsInfo[r.i].row.style.background = "yellow";
			} else {
				c.fillStyle = "black";
				subsInfo[r.i].row.style.background = "#CCC";
			}

			c.beginPath();
			c.rect(r.x, r.y, r.w, r.h);
			c.fill();
		}


		displayQuestions(selectedIdx);
	}


	function drawCursorLine(e) {
		var rect = c.canvas.getBoundingClientRect();
		var x = e.clientX - rect.left;
		var y = e.clientY - rect.top;

		var relativeX = x / c.canvas.width;
		var posX = relativeX * c.canvas.width;

		c.beginPath();
		c.moveTo(posX, 0);
		c.lineTo(posX, c.canvas.height);

		c.strokeStyle = "green";
		c.stroke();
	}

	c.canvas.onmousedown = function(e) {
		mouseIsDown = true;
	}

	c.canvas.onmouseup = function(e) {
		var rect = this.getBoundingClientRect();
		var x = e.clientX - rect.left;
		var y = e.clientY - rect.top;

		if(mouseIsDown && rightDivAppeared) mouseClick(e, x, y);

		drawCursorLine(e);
		mouseIsDown = false;

		function mouseClick(e, x, y) {
			var idx = -1;

			for(var i=0;i<questionRects.length;i++) {
				var r = questionRects[i];

				c.beginPath();
				c.rect(r.x, 0, r.w, c.canvas.height);

				if(c.isPointInPath(x, y)) {
					idx = i;
					break;
				}
			}

			if(idx == -1) {
				for(var i=0;i<questionRects.length;i++) {
					subsInfo[questionRects[i].i].isClicked = false;
				}
			} else {
				for(var i=0;i<questionRects.length;i++) {
					if(i == idx) subsInfo[questionRects[i].i].isClicked = true;
					else subsInfo[questionRects[i].i].isClicked = false;
				}
			}

			checkcolor(e);
		}
	}

	c.canvas.onmousemove = function(e) {
		checkcolor(e);
		drawCursorLine(e);
	}

	c.canvas.onmouseleave = function(e) {
		checkcolor(e);

		// not to draw cursor line
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

		c.fillStyle = "blue";

		function mouseClick(e, x, y) {
			var relativePosition = (x / c.canvas.width);

			moveTimeline(relativePosition);
			player.seekTo(relativePosition * player.getDuration());
		}
	}

	c.canvas.onmousemove = function(e) {
		questionBarC.canvas.onmousemove(e);
	}

	c.canvas.onmouseleave = function(e) {
		questionBarC.canvas.onmouseleave(e);
	}
}

function appearBtnClicked() {
	if(rightDivAppeared == false){
		rightDivAppeared = true;

		$('#leftDiv').animate({width: '65%'}, 200, function() { 
			$('#rightDiv').show(200, function() {

				var progressBarWidth = $('#progressBar').width();
				var progressBarHeight = $('#progressBar').height();

				var questionBarWidth = $('#questionBar').width();
				var questionBarHeight = $('#questionBar').height();

				resizeCanvas('progressBar', progressBarWidth, progressBarHeight);
				resizeCanvas('questionBar', questionBarWidth, questionBarHeight);

				plotQuestionBar(-1);
			});
		});
	}
}

function disappearBtnClicked() {
	if(rightDivAppeared == true) {
		rightDivAppeared = false;

		$('#rightDiv').hide(200, function() {
			$('#leftDiv').animate({width: '100%'}, 200, function() {

				var progressBarWidth = $('#progressBar').width();
				var progressBarHeight = $('#progressBar').height();

				var questionBarWidth = $('#questionBar').width();
				var questionBarHeight = $('#questionBar').height();

				resizeCanvas('progressBar', progressBarWidth, progressBarHeight);
				resizeCanvas('questionBar', questionBarWidth, questionBarHeight);

				plotQuestionBar(-1);
			});
		});
	}

}

$(document).ready(function() {
	/* ------ Submit button click event handling ------  */

	$('#submitBtn').click(function() {
		submitBtnClicked();
	});

	$('#appearBtn').click(function() {
		appearBtnClicked();
	});

	$('#disappearBtn').click(function() {
		disappearBtnClicked();
	});

	$('#leftSecond').on("mouseover", ".captionTable tr", function() {
		//captionOver($(this));
	});

	$('#leftSecond').on("mouseleave", ".captionTable tr", function() {
		//captionLeave($(this));
	});
/*
	$('#popBtn').click(function() {
		popBtnClicked();
	});*/

	/* ------ Question div click event handling ------  */
/*
	$('#rightSecond').on("click", ".questionElement", function() {
		contextPush($(this));
	});*/

	/* ------ Question bar mouse move setting ----- */

	questionBarMouseEffectSetting();

	/* ------ play bar mouse move setting ------ */
	progressBarMouseEffectSetting();
});

function captionOver(row) {
	row.css("background", "yellow");
}

function captionLeave(row) {
	row.css("background", "#CCC");
}

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
	var playerCurrentTime = Number(player.getCurrentTime() * 1000);

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

