Firebase Auth w/ Google Sign-In in Chrome Extensions
====================================================

This sample demonstrates how to authorize a user with Firebase in a Chrome extension using Google Sign-In and setup the Chrome extension to allow the use of the Realtime Database and Firebase Storage.

Feel free to try out a demo version of the Chrome Extension directly: https://chrome.google.com/webstore/detail/lpgchdfbjddonaolofeijjackhnhnlla

Introduction
------------

- [Read more about Firebase Auth](https://firebase.google.com/docs/auth/)

Setting up this sample
---------------

- Create a Firebase project using the [Firebase Console](https://console.firebase.google.com).
- Create a new OAuth Client ID in your project's [Developers Console](https://console.developers.google.com/apis/credentials/oauthclient?project=_), Select **Chrome App** and enter your Chrome Extension/App ID.
- In your project's Firebase Console, enable the **Google** authentication method in the **Auth** section > **SIGN IN METHOD** tab.
- Add the Client ID you created to the whitelist using the **Whitelist client IDs from external projects (optional)**
- Edit the `credential.js` and `background.js` and enter your project's identifiers you get from the Firebase Console **Overview > Add Firebase to your web app**.
- Edit the `manifest.json` and enter your **Client ID** and your extension's **Public Key**. Also make sure you remove all comment lines (starting with `//`) in the `manifest.json` file before deploying your extension online.
- Install the Extension in your browser and click on the extension's icon once installed. The first time your users will install the extension they will have to authorize Firebase using the login button.


Using Firebase in your own extension
------------------------------------

The keys to using Firebase in a Chrome extension are:
 - Becasue of Chrome Extensions' [Content Security Policy](https://developer.chrome.com/extensions/contentSecurityPolicy) you need to avoid inline JavaScript in your HTML pages so you need to add the Firebase initialisation snippet in your JS file instead of inside the HTML file as we [typically instruct](https://firebase.google.com/docs/web/setup). The Firebase initialisation snippet looks like this:
 
 ```javascript
 // Initialize Firebase
 var config = {
    apiKey: "<qwertyuiopasdfghjklzxcvbnm>",
    databaseURL: "https://<my-app-id>.firebaseio.com",
    storageBucket: "<my-app-id>.appspot.com"
 };
 firebase.initializeApp(config);
 ```

 - Create a Google Client ID that's authorized for your Chrome extension and whitelist it in your Firebase project:
   - Create a new OAuth Client ID in your project's [Developers Console](https://console.developers.google.com/apis/credentials/oauthclient?project=_), Select **Chrome App** and enter your Chrome Extension/App ID.
   - In your project's Firebase Console, enable the **Google** authentication method in the **Auth** section > **SIGN IN METHOD** tab.
   - Add the Client ID you created to the whitelist using the **Whitelist client IDs from external projects (optional)**
 - Use the chrome.identity API to get a Google OAuth token as described in https://developer.chrome.com/apps/app_identity and then use this token to authorize Firebase using [Auth.signInWithCredential()](https://firebase.google.com/docs/reference/js/firebase.auth.Auth#signInWithCredential):
 
 ```javascript
 var credential = firebase.auth.GoogleAuthProvider.credential(null, token);
 firebase.auth().signInWithCredential(credential);
 ```
 
 - Add the following content security policy to your `manifest.json` to allow importing the Firebase SDK and accessing the Realtime Database as well as Firebase Storage:
   
 ```javascript
 "content_security_policy":"script-src 'self' https://www.gstatic.com/ https://*.firebaseio.com https://www.googleapis.com; object-src 'self'"
 ```


Support
-------

https://firebase.google.com/support/

License
-------

© Google, 2016. Licensed under an [Apache-2](../../LICENSE) license.
