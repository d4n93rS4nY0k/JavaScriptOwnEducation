#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>
#include <ArduinoJson.h>

const char* ssid = "ESP8266_TOWER_Zасечка";
const char* password = "123456789";

IPAddress local_IP(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

const int MAX_RECORDS = 28; // Максимальное количество структур
String jsonPoints = "{\"records\":[]}";

void addDataToJson(String data) {
  StaticJsonDocument<8192> doc;
  DeserializationError error = deserializeJson(doc, jsonPoints);

  if (error) {
    Serial.println("Ошибка десериализации JSON. Сброс.");
    jsonPoints = "{\"records\":[]}";
    deserializeJson(doc, jsonPoints);
  }

  JsonArray records = doc["records"];

  if (records.size() >= MAX_RECORDS) {
    records.remove(0);
  }

  // Преобразуем строку в JSON объект
  StaticJsonDocument<512> newRecord;
  DeserializationError parseError = deserializeJson(newRecord, data);

  if (parseError) {
    Serial.println("Ошибка парсинга входных данных!");
    return;
  }

  records.add(newRecord);

  // Сохраняем обновленный JSON в строку
  jsonPoints = "";
  serializeJson(doc, jsonPoints);

  Serial.println("Данные добавлены. Текущий JSON:");
  serializeJsonPretty(doc, Serial);
}

// Обработка сообщений WebSocket
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo *)arg;
  if (info->opcode == WS_TEXT) {
    String message = String((char *)data).substring(0, len);

    if (message == "getData") {
      ws.textAll(jsonPoints); // Отправка накопленных данных клиентам
    }
  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  if (type == WS_EVT_DATA) {
    handleWebSocketMessage(arg, data, len);
  }
}

void setup() {
  Serial.begin(115200);

  // Настройка Wi-Fi точки доступа
  if (!WiFi.softAPConfig(local_IP, gateway, subnet)) {
    Serial.println("Не удалось настроить статический IP!");
    return;
  }

  WiFi.softAP(ssid, password);
  Serial.print("Точка доступа \"");
  Serial.print(ssid);
  Serial.println("\" запущена");
  Serial.print("IP адрес: ");
  Serial.println(WiFi.softAPIP());

  if (!LittleFS.begin()) {
    Serial.println("Ошибка монтирования LittleFS");
    return;
  }

  server.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");
  ws.onEvent(onEvent);
  server.addHandler(&ws);

  server.begin();
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    addDataToJson(data); // Накопление данных
  }

  ws.cleanupClients();
}
