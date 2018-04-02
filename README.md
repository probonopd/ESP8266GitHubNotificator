# ESP8266GitHubNotificator

![](https://user-images.githubusercontent.com/2480569/38193609-28857d5a-3673-11e8-9594-56d4900e058b.jpg)

The ESP8266 lights up the built-in blue LED if you have GitHub notifications waiting.

## Theory of operation

The sketch polls the GitHub Notfications API every 60 seconds using a personal GitHub token

## Setup

Go to https://github.com/settings/tokens, click on "Generate new token", check "notifications", click "Generate token". Copy the resulting token into the sketch at

```
const String github_token = "...";
```

Upload the sketch. Connect to the `AutoConnectAP` WLAN access point, set up your WLAN credentials
