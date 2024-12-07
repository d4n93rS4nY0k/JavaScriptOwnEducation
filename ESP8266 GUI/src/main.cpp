#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>
#include <ArduinoJson.h>

const char* ssid = "ESP8266_TOWER_Zasечка";
const char* password = "123456789";

IPAddress local_IP(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

const int MAX_RECORDS = 28;
DynamicJsonDocument doc(32768);
JsonArray records = doc.createNestedArray("records");

String buffer = "";

void addDataToJson(String data) {
  if (records.size() >= MAX_RECORDS) {
    records.remove(0);
  }

  DynamicJsonDocument newRecord(512);
  DeserializationError error = deserializeJson(newRecord, data);

  if (error) {
    Serial.println("Parsing data error!");
    return;
  }
  records.add(newRecord);
}

void handleWebSocketMessage(void* arg, uint8_t* data, size_t len) {
  AwsFrameInfo* info = (AwsFrameInfo*)arg;
  if (info->opcode == WS_TEXT) {
    String message = String((char*)data).substring(0, len);

    if (message == "getData") {
      if (records.size() == 0) {
        Serial.println("No data to send. Skipping transmission.");
        return;
      }
      String json;

      serializeJson(doc, json);
      ws.textAll(json);
      Serial.println("Data send to clients");
      Serial.println(records.size());

      records.clear();
      Serial.println("JSON-file cleared");
    }
  }
}

void onEvent(AsyncWebSocket* server, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len) {
  if (type == WS_EVT_DATA) {
    handleWebSocketMessage(arg, data, len);
  }
}

void setup() {
  Serial.begin(115200);

  if (!WiFi.softAPConfig(local_IP, gateway, subnet)) {
    Serial.println("Error in setting static IP!");
    return;
  }

  WiFi.softAP(ssid, password);
  Serial.print("SSID ");
  Serial.print(ssid);
  Serial.println(" ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

  if (!LittleFS.begin()) {
    Serial.println("Error mounting LittleFS");
    return;
  }

  server.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");
  ws.onEvent(onEvent);
  server.addHandler(&ws);

  server.begin();
}

#define BUFFER_SIZE 1024
char ringBuffer[BUFFER_SIZE];
size_t bufferHead = 0;

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    ringBuffer[bufferHead] = c;
    bufferHead = (bufferHead + 1) % BUFFER_SIZE;

    if (c == '\n') {
      ringBuffer[bufferHead] = '\0';
      String line = String(ringBuffer);
      addDataToJson(line);
      bufferHead = 0;
    }
  }

  ws.cleanupClients();
}
