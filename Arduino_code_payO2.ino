#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
                          
#define FIREBASE_HOST "pay02-59367-default-rtdb.firebaseio.com"                     //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "zdYDzo7kcnIeqaq6uMRzXfv3VKGpeNquluHoS5Kj" //Your Firebase Database Secret goes here

#define WIFI_SSID "yuvraj"                                               //WiFi SSID to which you want NodeMCU to connect
#define WIFI_PASSWORD "12345678"                                      //Password of your wifi network 
int smokeA0 = A0;
  

// Declare the Firebase Data object in the global scope
FirebaseData firebaseData;

void setup() {

  Serial.begin(115200);                                   // Select the same baud rate if you want to see the datas on Serial Monitor
  pinMode(smokeA0, INPUT);
  Serial.println("Serial communication started\n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);


  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

  Firebase.reconnectWiFi(true);
  delay(1000);
}

void loop() { 
int analogSensor = analogRead(smokeA0);
// Firebase Error Handling And Writing Data At Specifed Path************************************************


if (Firebase.setInt(firebaseData, "/carbonEmission", analogSensor)) {    // On successful Write operation, function returns 1  
               Serial.println("Value Uploaded Successfully to smart Contract");
               Serial.print("Carbon Emission = ");
               Serial.println(analogSensor);
               Serial.println("\n");
           

     }

else {        
    Serial.println(firebaseData.errorReason());
  }

}



       
