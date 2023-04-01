#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WebSocketsClient.h>
#include <ArduinoJson.h>
#include <string.h>
#include <SoftwareSerial.h>
#include <Web3.h>

const char* ssid = "yuvraj";
const char* password = "12345678";

const char* web3Provider = "remix.etherum.org";
const char* contractAddress = "0x80c8A8c9C122519076d471eC1BDcAc3e310eD622";
const char* privateKey = "zdYDzo7kcnIeqaq6uMRzXfv3VKGpeNquluHoS5Kj";

const int sensorPin = A0;

Web3 web3(web3Provider);
Web3Contract contract(web3, contractAddress);

SoftwareSerial softSerial(4, 5); // RX, TX

void setup() {
  pinMode(sensorPin, INPUT);

  Serial.begin(9600);
  softSerial.begin(9600);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  web3.setPrivateKey(privateKey);
}

void loop() {
  float sensorValue = analogRead(sensorPin);
  Serial.print("Temperature: ");
  Serial.println(temperature);

  DynamicJsonDocument doc(128);
  doc["data"] = sensorValue;

  String jsonStr;
  serializeJson(doc, jsonStr);

  Serial.println("Sending data to smart contract...");

  contract.call("sendData", jsonStr.c_str());

  delay(5000); // Wait 5 seconds before sending the next data point
}
