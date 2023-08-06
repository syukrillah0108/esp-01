#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "lenovo"; //Nama SSID AP/Hotspot
const char* password = "1234567890"; //Password Wifi
IPAddress staticIP(192, 168, 12, 7); // Alamat IP statis yang ingin Anda gunakan
IPAddress gateway(192, 168, 12, 1); // Gateway (alamat IP router Wi-Fi)
IPAddress subnet(255, 255, 255, 0); // Subnet mask

ESP8266WebServer server(80); //Menyatakan Webserver pada port 80

void handleRoot();

void handleON(int pin);

void handleOFF(int pin);

void setup() {
  //Serial.begin(9600);
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
// Mengatur WiFi 
  WiFi.mode(WIFI_STA); // Mode Station
  WiFi.begin(ssid, password); // Mencocokan SSID dan Password
  WiFi.config(staticIP, gateway, subnet); // Mengatur IP statis, gateway, dan subnet mask
    
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

// Tampilkan status Connected 
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

// Setup URL
  server.on("/", handleRoot);

    server.on("/0on", []() {
        handleON(0); // Panggil fungsi handleON dengan parameter
    });
    server.on("/0off", []() {
        handleOFF(0); // Panggil fungsi handleOFF dengan parameter
    });

    server.on("/1on", []() {
        handleON(1); // Panggil fungsi handleON dengan parameter
    });
    server.on("/1off", []() {
        handleOFF(1); // Panggil fungsi handleOFF dengan parameter
    });

    server.on("/2on", []() {
        handleON(2); // Panggil fungsi handleON dengan parameter
    });
    server.on("/2off", []() {
        handleOFF(2); // Panggil fungsi handleOFF dengan parameter
    });

    server.on("/3on", []() {
        handleON(3); // Panggil fungsi handleON dengan parameter
    });
    server.on("/3off", []() {
        handleOFF(3); // Panggil fungsi handleOFF dengan parameter
    });

    server.on("/4on", []() {
        handleON(4); // Panggil fungsi handleON dengan parameter
    });
    server.on("/4off", []() {
        handleOFF(4); // Panggil fungsi handleOFF dengan parameter
    });

  server.begin();

  Serial.println("Webserver dijalankan");
}

void loop() {
   server.handleClient();
}

void handleRoot() {
  //server.send(200, "text/plain", "HOME");
}

void handleON(int pin){
  digitalWrite(pin, HIGH);
  //server.send(200, "text/plain", "ON");
}

void handleOFF(int pin){
  digitalWrite(pin, LOW);
  //server.send(200, "text/plain", "OFF");
}