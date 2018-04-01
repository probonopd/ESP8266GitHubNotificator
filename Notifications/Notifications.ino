#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <Ticker.h>

const String github_token = "...";

const char* host = "api.github.com";
const int httpsPort = 443;

Ticker checker;

bool check_now = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(115200);
  WiFiManager wifiManager;
  wifiManager.autoConnect("AutoConnectAP");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  mark_to_be_checked();
  checker.attach(60, mark_to_be_checked);
}

void mark_to_be_checked() {
  check_now = true;
}

void check() {
  WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }

  String url = "/notifications?access_token=" + github_token;
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: ESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("GET request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line.startsWith("Content-Length:")) {
      Serial.println(line.substring(16));
      int length = line.substring(16).toInt();
      if (length > 10) {
        Serial.println("We have notifications");
        digitalWrite(LED_BUILTIN, LOW);
      } else {
        digitalWrite(LED_BUILTIN, HIGH);
      }
    }
    if (line == "\r") {
      Serial.println("headers received");
      client.stop();
      break;
    }
  }
  client.stop();
}

void loop() {
  if (check_now == true) {
    check();
    check_now = false;
  }
}
