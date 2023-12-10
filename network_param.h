#ifndef _NETWORK_PARAM_H
#define _NETWORK_PARAM_H

// Getting Access Token : 
// At first, you should get service account key (JSON file).
// Type below command in Google Cloud Shell to get AccessToken: 
// $ gcloud auth activate-service-account --key-file=KEY_FILE   (KEY_FILE is your service account key file)
// $ gcloud auth print-access-token
// The Access Token is expired in an hour.
// Google recommends to use Access Token.
// const String AccessToken = "";

// It is also possible to use "API Key" instead of "Access Token". It doesn't have time limit.
const String ApiKey = "AIzaSyAQDYMUl5P4E9XP--VtTQlJZ2j4k1o9tio";

// see https://cloud.google.com/docs/authentication?hl=ja#getting_credentials_for_server-centric_flow
// see https://qiita.com/basi/items/3623a576b754f738138e (Japanese)

#endif  // _NETWORK_PARAM_H