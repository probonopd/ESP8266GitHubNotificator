# ESP8266GitHubNotificator: ![bell](https://user-images.githubusercontent.com/2480569/38178171-8423b9c8-35fc-11e8-94ad-3329e2fa6dd5.png) in hardware

The ESP8266 lights up the built-in blue LED if you have GitHub notifications waiting.

## Theory of operation

The sketch polls the GitHub Notfications API every 60 seconds using a personal GitHub token

## Setup

Go to https://github.com/settings/tokens, click on "Generate new token", check "notifications", click "Generate token". Copy the resulting token into the sketch at

```
const String github_token = "...";
```

Upload the sketch. Connect to the `AutoConnectAP` WLAN access point, set up your WLAN credentials
