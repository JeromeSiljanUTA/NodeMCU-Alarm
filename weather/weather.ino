// Libraries
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <string.h>
#include <time.h>
#include "Display.h"

// WiFi Setup
const char *ssid = "Frontier1312";
const char *password = "2891547465";

ESP8266WebServer server(80);

#define MY_NTP_SERVER "at.pool.ntp"
#define MY_TZ "CST6CDT"

#define LATCH_PIN 16

void setup() {
    // PinModes
    pinMode(LATCH_PIN, OUTPUT);

    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(0, OUTPUT);
    pinMode(2, OUTPUT);

    pinMode(14, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(15, OUTPUT);

    Serial.begin(115200);


    /*
    setWifi();
    setOn();
    server.begin();

    configTime(MY_TZ, MY_NTP_SERVER);
    */

}

Display disp[] = {Display(5, 4, 0, 2), Display(14, 12, 13, 15)};

void loop() {
    //server.handleClient();
    for(int i = 0; i < 100; i++){
        printNum(i, disp);
        updateDisplay();
        delay(50);
    }
} 

void printNum(int num, Display disp[2]){
    int tens = num/10;
    int ones = num%10;
    disp[0].writeNum(tens);
    disp[1].writeNum(ones);
}

void updateDisplay(){
    digitalWrite(LATCH_PIN, HIGH);
    digitalWrite(LATCH_PIN, LOW);
}

// WebServer Stuff
void setWifi(){
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(WiFi.localIP());
}

void setOn(){
    server.on ("/", handleRoot);
}

void handleRoot() {
    String mainpage = "";
    mainpage += "<!DOCTYPE html>";
    mainpage += "<html>";
    mainpage += "<head>";
    mainpage += "<h1 id=\"header\">Weather Display</h1>";

    server.send(200, "text/html", mainpage);
}
