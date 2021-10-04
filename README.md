# WebSocket Tester

## What is Websocket Tester?
Websocket Tester is a client app to test connection to WebSocket Server. [Websocket Tester](https://play.google.com/store/apps/details?id=com.invokcontroller.app) is now available on Google Play.

## Test Server
Websocket Tester has been tested with ESP8266 as a WebSocket server. The server (ESP8266) will respond Ping with Pong, send 'hello' upon connection request from client, and echo back the message sent from the app. This test server uses the following library:
- [WiFi](https://github.com/arduino-libraries/WiFi)
- [ESP8266WiFi](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)
- [WebSockets](https://github.com/Links2004/arduinoWebSockets)

## Disclaimer
This library is still a work in progress. There may be some breaking changes in the future, which might require you to replace, re-organize, and rearrange functions or variables included in this library. Use this library at your own risk.

## Supported Development Board
- ESP32 Development Board Family (WiFi)
- ESP8266 Development Board Family (WiFi)

## Basic Functionality
- Ping/Pong
- Echo
- Connection acknowledgement

## Quickstart
- Download the [WebSocket Tester](https://play.google.com/store/apps/details?id=com.invokcontroller.app) app from Google Play Store.
- Install the following library:
    - [WiFi](https://github.com/arduino-libraries/WiFi)
    - [ESP8266WiFi](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)
    - [WebSockets](https://github.com/Links2004/arduinoWebSockets)
- Download/clone this repository.
- Compile and upload example sketch.
- Reset the board, the built-in LED will light up, this indicate the board is is Wi-Fi setup mode.
- Connect to the board via Wi-Fi, SSID should be something like ESP_XXXXXX.
- Most of the time you will be automatically redirected to configuration page, if not, open browser and go to __1.1.1.1__
- Click on __Configure WiFi__, tap the SSID you want to connect to or manually enter SSID and password. Once you are done, save, then the ESP will restart.
- Open the app and enter IP Address printed on serial monitor to the Address Bar.
- Press __Connect__, when connection is established, server will send __'hello'__, and the app status will change to __'CONNECTED'__
- Test connection by sending message. Server will respond or echo back the same message.
