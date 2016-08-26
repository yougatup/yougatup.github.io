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

var questionType = makeQuestionStruct("index time question answer div");
var currentPoint = -1;
var questionList = [];

function checkQuestion(time) {
	while(currentPoint-1 >= 0 && questionList[currentPoint].time >= time) {
		questionList[currentPoint].div.hide();

		currentPoint--;
	}

	while(currentPoint+1 < questionList.length && questionList[currentPoint+1].time < time) {
		questionList[currentPoint+1].div.show();

		currentPoint++;
	}
}

function moveTimeline(percent) {
	var ctx = document.getElementById("progressBar");
	var c = ctx.getContext("2d");

	var progressBarWidth = percent * c.canvas.width / 100;

	$("#leftSecond").text(progressBarWidth+ " " + $("#progressBar").width() + " " + c.canvas.width + " " + c.canvas.height + " " + questionList.length + " " + $("#questionBar").width());

	c.fillStyle = "#FFFFFF";
	c.fillRect(0, 0, progressBarWidth, c.canvas.height);

	c.fillStyle = "#AAA";
	c.fillRect(progressBarWidth, 0, c.canvas.width, c.canvas.height);
}

function plotQuestionBar() {
	for(var i=0;i<questionList.length;i++){
		plotSingleQuestion(questionList[i].time);
	}
}

function plotSingleQuestion(questionTime) {
	var ctx = document.getElementById("questionBar");
	var c = ctx.getContext("2d");

	var playerTotalTime = player.getDuration();
	var relativePosition = (questionTime / playerTotalTime) * 100;

	var drawPosition = relativePosition * c.canvas.width / 100;

	c.beginPath();
	c.moveTo(drawPosition, 0);
	c.lineTo(drawPosition, c.canvas.height);
	c.stroke();
}


var tag = document.createElement('script');

tag.src = "https://www.youtube.com/iframe_api";
var firstScriptTag = document.getElementsByTagName('script')[0];
firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);

// 3. This function creates an <iframe> (and YouTube player)
//    after the API code downloads.
var player;

function onYouTubeIframeAPIReady() {
	player = new YT.Player('leftFirst', {
		height: '540',
		   width: '960',
		   videoId: 'UDxzMcCrOyI',
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
	event.target.playVideo();
	clearQuestionBox();

	/* ------ bind ctrl + l to submitting question -- */

	jQuery('#questionBox').bind('keydown', 'ctrl+l', submitBtnClicked);

	/* ------ Progress Bar Initialization ------ */

	var printedWidth = $('#progressBar').width();
	var printedHeight = $('#progressBar').height();

	resizeCanvas('progressBar', printedWidth, printedHeight);
	resizeCanvas('questionBar', printedWidth, printedHeight);

	$('#progressBar').show();
	$('#questionBar').show();

	/* ------ Preparing for regular job ----- */

	var playerTotalTime = player.getDuration();

	setInterval(function() {
		var playerCurrentTime = player.getCurrentTime();

		var playerTimeDifference = (playerCurrentTime / playerTotalTime) * 100;

		moveTimeline(playerTimeDifference);

		checkQuestion(playerCurrentTime);
	}, 100);        

	/* --------- Initialize question list --------- */

	registerQuestion(10, "aa");
	registerQuestion(30, "bb");
	registerQuestion(50, "cc");
	registerQuestion(40, "cc");
	registerQuestion(20, "cool");
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


$(document).ready(function() {
	/* ------ Submit button click event handling ------  */

	$('#submitBtn').click(function() {
		submitBtnClicked();
	});
});


function submitBtnClicked() {
	var playerCurrentTime = player.getCurrentTime();

	registerQuestion(playerCurrentTime, getQuestionStatement());
	clearQuestionBox();
}

function getQuestionStatement() {
	return $('#questionBox').val();
}

function clearQuestionBox() {
	$('#questionBox').val('');
}

function registerQuestion(time, statement) {
	var idx = questionList.length;

	//questionList.push(new questionType(idx, time, statement));

	var $newdiv = $('<div />',{
		'id': "question"+idx,
		'text': time + " " + statement,
		'class': "questionElement",
		'height': '100px',
	});

	$newdiv.hide();
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
	} else {
		var Id = questionList[insertIndex].div[0].id;
		questionList.splice(insertIndex, 0, new questionType(idx, time, statement, '', $newdiv));

		$newdiv.insertAfter("#" + Id);
	}

	plotSingleQuestion(time);
}

