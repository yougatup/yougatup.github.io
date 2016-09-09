
var words = [];
var cnt = 0;
var ready = false;
var Testname = 'Day6';

function questionRowForm(element) {
	return '<tr>' + 
		'<td> ' + (element.index) + ' </td>' + 
		'<td> ' + (element.question) + ' </td>' +
		'<td> <input id=input' + (element.index) + '> </input> </td>' +
		'</tr>';
}

function addQuestion(element) {
	$('#wordTable tr:last').after(questionRowForm(element));
}

$(document).ready(function() {
	InitializeDB();
	toggleSignIn();
	readData();

	$(document).on('click', '#submitBtn', function() {
		// submit results

		flushData();

		alert("submit done! Let's see the answer sheet !");

		window.location.replace("http://yougatup.github.io/englishStudy/total.html");

	});
});


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

function registerWords(index, question, key) {
	words.push({
		index: index,
	question: question,
	key: key
	});
}

function compare(a, b) {
	if (a.index < b.index) return -1;
	else if(a.index > b.index) return 1;
	else return 0;
}

function readData() {
	var questionRef = firebase.database().ref('englishTest/' + Testname);

	function shuffle(a) {
		var j, x, i;
		for (i = a.length; i; i--) {
			j = Math.floor(Math.random() * i);
			x = a[i - 1];
			a[i - 1] = a[j];
			a[j] = x;
		}
	}

	questionRef.once("value", function(snapshot) {
		var obj = snapshot.val()
		for (var key in obj) {
			if (obj.hasOwnProperty(key)) {
				registerWords(obj[key].index, obj[key].question, key);
			}
		}

	displayWordTable();

	//		words.sort(compare);

	shuffle(words);

	for(var i=0;i<words.length;i++) {
		addQuestion(words[i]);
	}

	}, function (errorObject) {
		console.log("The read failed: " + errorObject.code);
	});
}

function displayWordTable() {
	$('#main').html(
			'<h1>' + Testname + '</h1>' + 
			'<table id=\'wordTable\'>' + 
			'<tr>' + 
			'<th> Index </th>' + 
			'<th> Word </th>' + 
			'<th> Answer </th>' + 
			'</tr>' + 
			'</table>' + 
			'<button id=submitBtn>Submit</button>'
			);
}

function writeToDB(index, question, answer) {
	// A post entry.
	var postData = {
		'index': index,
		'question': question,
		'answer': answer,
		'submitted': '',
	};

	// Get a key for a new Post.
	var newPostKey = firebase.database().ref().child('englishTest/' + Testname).push().key;

	// Write the new post's data simultaneously in the posts list and the user's post list.
	var updates = {};
	updates['/englishTest/' + Testname + '/' + newPostKey] = postData;

	return firebase.database().ref().update(updates);
}

function flushData() {
	var updates = {};
	for(var i=0;i<words.length;i++) {
		var inputID = "input" + words[i].index;
		var myValue = $('#' + inputID).val();

		updates['/englishTest/' + Testname + '/' + words[i].key + '/submitted'] = myValue;
	}

	return firebase.database().ref().update(updates);
}
