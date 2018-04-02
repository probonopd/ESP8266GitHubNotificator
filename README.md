# ESP8266GitHubNotificator

![](https://user-images.githubusercontent.com/2480569/38193609-28857d5a-3673-11e8-9594-56d4900e058b.jpg)

The ESP8266 lights up the built-in blue LED if you have GitHub notifications waiting.

## Theory of operation

An ESP8266 module such as a [WEMOS D1 mini](https://wiki.wemos.cc/products:d1:d1_mini) is running a simple [esp8266/Arduino](https://github.com/esp8266/Arduino) sketch. The sketch polls the GitHub Notfications API every 60 seconds using a personal GitHub token and lights the built-in LED if there ware notifications available.

## Hardware assembly

3D print a nice looking case. Use transparent filament for the area where the blue LED will shine through.

## Software setup

Compile and upload the sketch to the WEMOS D1 mini (or another ESP8266 board) using the Arduino IDE and [esp8266/Arduino](https://github.com/esp8266/Arduino).

Go to https://github.com/settings/tokens, click on "Generate new token", check "notifications", click "Generate token". Copy the resulting token into the sketch at

```
const String github_token = "...";
```

Upload the sketch. Connect to the `AutoConnectAP` WLAN access point, set up your WLAN credentials.

## Your contributions are welcome

This is a simple sketch but we still have many ideas, [have a look here](https://github.com/probonopd/ESP8266GitHubNotificator/issues) and send pull requests.
