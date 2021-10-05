#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <WebSocketsServer.h>
#include <string>
#include <vector>

// Globals
WebSocketsServer websocket = WebSocketsServer(80);
WiFiManager wm;

// Called when receiving any WebSocket message
void onWebSocketEvent(uint8_t num,
                      WStype_t type,
                      uint8_t * payload,
                      size_t length) {

  // Figure out the type of WebSocket event
  switch(type) {

    // Client has disconnected
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;

    // New client has connected
    case WStype_CONNECTED:
    {
      IPAddress ip = websocket.remoteIP(num);
      Serial.printf("[%u] Connection from ", num);
      Serial.println(ip.toString());
      break;
    }
    
    case WStype_TEXT:
      // Echo text message back to client
      websocket.sendTXT(num, payload);
      break;

    case WStype_PING:
      // Serial.println("PING Received");
      break;

    // For everything else: do nothing
    case WStype_BIN:
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
    default:
      break;
  }
}

void setup() {
    WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP

    // put your setup code here, to run once:
    Serial.begin(115200);
    
    // Set Internal LED Pin
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    //WiFiManager, Local intialization. Once its business is done, there is no need to keep it around
    // Turn off debug mode
    wm.setDebugOutput(true);
    
    // Set IP Address
    wm.setAPStaticIPConfig(IPAddress(1,1,1,1), IPAddress(1,1,1,1), IPAddress(255,255,255,0));
    bool res;
    res = wm.autoConnect(); // auto generated AP name from chipid

    if(!res) {
      Serial.println("Failed to connect");
      // ESP.restart();
    } 
    else {
      //if you get here you have connected to the WiFi    
      Serial.println("Connected to Wi-Fi");
      Serial.println(wm.getDefaultAPName());
      Serial.println(WiFi.SSID());  
      Serial.println(WiFi.localIP());

      websocket.begin();
      websocket.onEvent(onWebSocketEvent);
    }  
}

void loop() {
    // Websocket Loop
    websocket.loop();
}