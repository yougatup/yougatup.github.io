function progress(percent, $element) {
	var progressBarWidth = percent * $element.width() / 100;

	$("#leftSecond").text(progressBarWidth+ " " + $element.width());

	$element.find('div').animate({ width: progressBarWidth });
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

// 4. The API will call this function when the video player is ready.
function onPlayerReady(event) {
	event.target.playVideo();
	clearQuestionBox();

	/* ------ bind ctrl + l to submitting question -- */

	jQuery('#questionBox').bind('keydown', 'ctrl+l', submitBtnClicked);

	/* ------ Progress Bar Initialization ------ */

	$('#progressBar').show();
	var playerTotalTime = player.getDuration();

	setInterval(function() {
		var playerCurrentTime = player.getCurrentTime();

		var playerTimeDifference = (playerCurrentTime / playerTotalTime) * 100;

		progress(playerTimeDifference, $('#progressBar'));
	}, 300);        

	/* ---------------------------------------- */
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

var questionCnt = 0;
var questionArray = [];

function submitBtnClicked() {
	addElement(getQuestionStatement());
	clearQuestionBox();

}

function getQuestionStatement() {
	return $('#questionBox').val();
}

function clearQuestionBox() {
	$('#questionBox').val('');
}

function addElement(statement) {
	//statement = statement.replace(/\r?\n/g, '\\r\\n');
	var $newdiv = $('<div />',{
		'id': "question"+questionCnt,
		'text': statement,
		'class': "questionElement",
		'height': '100px',
	});

	$newdiv.animate({height: 'toggle'});

	$('#rightSecond').prepend($newdiv);

	questionArray.unshift($newdiv); // push from beginning

	questionCnt++;
}
