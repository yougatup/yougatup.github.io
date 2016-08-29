
var questionType = makeQuestionStruct("index time question answer div");
var currentPoint = -1;
var questionList = [];
var videoId = '5-ZFOhHQS68';
var subsInfo = [];
var subsFrequency = [];
var questionRects = [];
var clickedRect;

// Newton's first law of motion 2 : D1NubiWCpQg

var tag = document.createElement('script');

tag.src = "https://www.youtube.com/iframe_api";
var firstScriptTag = document.getElementsByTagName('script')[0];
firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);

// 3. This function creates an <iframe> (and YouTube player)
//    after the API code downloads.
var player;
var contextStack = [];

function makeQuestionStruct(names) {
	var names = names.split(' ');
	var count = names.length;

	function constructor() {
		for (var i = 0; i < count; i++) {
			this[names[i]] = arguments[i];
		}
	}

	return constructor;
}
function checkQuestion(time) {
	while(currentPoint >= 0 && questionList[currentPoint].time >= time*1000) {
		questionList[currentPoint].div.slideUp();

		currentPoint--;
	}

	while(currentPoint+1 < questionList.length && questionList[currentPoint+1].time < time*1000) {
		questionList[currentPoint+1].div.slideDown();

		currentPoint++;
	}
}

function moveTimeline(percent) {
	var ctx = document.getElementById("progressBar");
	var c = ctx.getContext("2d");

	var progressBarWidth = percent * c.canvas.width / 100;

	$("#leftSecond").text("current time : " + player.getCurrentTime());

	c.fillStyle = "#FFFFFF";
	c.fillRect(0, 0, progressBarWidth, c.canvas.height);

	c.fillStyle = "#AAA";
	c.fillRect(progressBarWidth, 0, c.canvas.width, c.canvas.height);
}

function plotQuestionBar() {
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

	clickedRects = {
		x: -1,
		y: -1,
		w: -1,
		h: -1
	};

	for(var i=1;i<subsFrequency.length;i++) { // subsInfo starts from 1
		// plot rectangle in subsInfo[i].start ~ subsInfo[i].end

		var startPoint = ((subsInfo[i].start/1000) / player.getDuration()) * c.canvas.width;
		var endPoint = ((subsInfo[i].end/1000) / player.getDuration()) * c.canvas.width;
		var myHeight = (subsFrequency[i] / max) * c.canvas.height;

		questionRects.push( {
			x: startPoint, 
			y: (c.canvas.height - myHeight), 
			w: endPoint - startPoint, 
			h: myHeight,
			c: false,
			i: i
		});
	}

	c.fillStyle = "#000000";

	for(var i=0;i<questionRects.length;i++) {
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

		//checkQuestion(playerCurrentTime);
	}, 100);        

	/* --------- Initialize question list --------- */

	loadDataFromFirebase();

	/* --------- Initialize subtitle information ---- */

	loadSubsInfoFromFirebase();

	/* ----------Context stack initialize----------- */

	contextStack.push($('#mySlider'));
}

function getQuestionHistogram() {
	for(var j=0;j<subsInfo.length;j++)
		subsFrequency[j] = 0;

	for(var i=0;i<questionList.length;i++) {
		for(var j=1;j<subsInfo.length;j++) { // subsInfo starts from 1
			if(subsInfo[j].start <= questionList[i].time && questionList[i].time < subsInfo[j].end) {
				subsFrequency[j] = subsFrequency[j] + 1;
				break;
			}
		}
	}
}

function loadSubsInfoFromFirebase() {
	var subsInfoRef	= firebase.database().ref('subsInfo/' + videoId);

	subsInfoRef.once("value", function(snapshot) {
		var obj = snapshot.val()
		for (var key in obj) {
			if (obj.hasOwnProperty(key)) {
				subsInfo[obj[key].index] = {
					'start': obj[key].start,
		'end': obj[key].end,
		'statement': obj[key].statement
				};
			}
		}

		getQuestionHistogram();
		plotQuestionBar();

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

		c.clearRect(0, 0, c.canvas.width, c.canvas.height);

		for(var i=0;i<questionRects.length;i++) {
			var r = questionRects[i];

			c.beginPath();
			c.rect(r.x, 0, r.w, c.canvas.height);

			if(r.c == true || c.isPointInPath(x, y)) {
				selectedIdx = (r.c == true) ? i : -1;
				c.fillStyle = "red";
			} else {
				c.fillStyle = "black";
			}

			c.beginPath();
			c.rect(r.x, r.y, r.w, r.h);
			c.fill();
		}

		if(selectedIdx != -1) {
			var subsInfoIdx = questionRects[selectedIdx].i;

			for(var i=0;i<questionList.length;i++) {
				if(subsInfo[subsInfoIdx].start <= questionList[i].time && questionList[i].time < subsInfo[subsInfoIdx].end) {
					questionList[i].div.slideDown();
				} else {
					questionList[i].div.slideUp();
				}
			}
		}
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

		c.strokeStyle = "red";
		c.stroke();
	}

	c.canvas.onmousedown = function(e) {
		mouseIsDown = true;
	}

	c.canvas.onmouseup = function(e) {
		var rect = this.getBoundingClientRect();
		var x = e.clientX - rect.left;
		var y = e.clientY - rect.top;

		if(mouseIsDown) mouseClick(e, x, y);

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
					questionRects[i].c = false;
				}
			} else {
				for(var i=0;i<questionRects.length;i++) {
					if(i == idx) questionRects[i].c = true;
					else questionRects[i].c = false;
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

$(document).ready(function() {
	/* ------ Submit button click event handling ------  */

	$('#submitBtn').click(function() {
		submitBtnClicked();
	});

	$('#popBtn').click(function() {
		popBtnClicked();
	});

	/* ------ Question div click event handling ------  */

	$('#rightSecond').on("click", ".questionElement", function() {
		contextPush($(this));
	});

	/* ------ Question bar mouse move setting ----- */

	questionBarMouseEffectSetting();

	/* ------ play bar mouse move setting ------ */
	progressBarMouseEffectSetting();
});

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

function popBtnClicked() {
	while(contextStack.length > 1) {
		var popElement = contextStack.pop();

		popElement.remove();

		contextStack[contextStack.length-1].show();
	}
}

function submitBtnClicked() {
	var playerCurrentTime = player.getCurrentTime();

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

function registerQuestion(time, statement, displayResult) {
	var idx = questionList.length;

	var $newdiv = $('<div />',{
		'id': "question"+idx,
		'text': time + "\n" + statement,
		'class': "questionElement",
	});


	var insertIndex = -1;

	for(var j=0;j<questionList.length;j++) {
		if(questionList[j].time > time) {
			insertIndex = j;
			break;
		}
	}

	if(insertIndex == -1) {
		questionList.push(new questionType(idx, time, statement, '', $newdiv));

		$('#rightSecond').prepend($newdiv);

		questionList[questionList.length-1].div.slideUp(0);
	} else {
		var Id = questionList[insertIndex].div[0].id;
		questionList.splice(insertIndex, 0, new questionType(idx, time, statement, '', $newdiv));

		$newdiv.insertAfter("#" + Id);

		questionList[insertIndex].div.slideUp(0);
	}

	if(displayResult == true) {
		plotSingleQuestion(time);
	}
}

