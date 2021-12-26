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

#define LATCH_PIN 0

void setup() {
    // PinModes
    pinMode(16, OUTPUT);

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

Display disp1(3);

void loop() {
    //server.handleClient();
    writeNum(disp1.getVal(), 1);
} 

void writeNum(int num, int display){
    if(display == 1){
        display = 5;
    }
    else{
        display = 1;
    }

    switch(num){
        case 0:
            shiftWrite(0 + display, LOW);
            shiftWrite(1 + display, LOW);
            shiftWrite(2 + display, LOW);
            shiftWrite(3 + display, LOW);
            break;
        case 1:
            shiftWrite(0 + display, HIGH);
            shiftWrite(1 + display, LOW);
            shiftWrite(2 + display, LOW);
            shiftWrite(3 + display, LOW);
            break;
        case 2:
            shiftWrite(0 + display, LOW);
            shiftWrite(1 + display, HIGH);
            shiftWrite(2 + display, LOW);
            shiftWrite(3 + display, LOW);
            break;
        case 3:
            shiftWrite(0 + display, HIGH);
            shiftWrite(1 + display, HIGH);
            shiftWrite(2 + display, LOW);
            shiftWrite(3 + display, LOW);
            break;
        case 4:
            shiftWrite(0 + display, LOW);
            shiftWrite(1 + display, LOW);
            shiftWrite(2 + display, HIGH);
            shiftWrite(3 + display, LOW);
            break;
        case 5:
            shiftWrite(0 + display, HIGH);
            shiftWrite(1 + display, LOW);
            shiftWrite(2 + display, HIGH);
            shiftWrite(3 + display, LOW);
            break;
        case 6:
            shiftWrite(0 + display, LOW);
            shiftWrite(1 + display, HIGH);
            shiftWrite(2 + display, HIGH);
            shiftWrite(3 + display, LOW);
            break;
        case 7:
            shiftWrite(0 + display, HIGH);
            shiftWrite(1 + display, HIGH);
            shiftWrite(2 + display, HIGH);
            shiftWrite(3 + display, LOW);
            break;
        case 8:
            shiftWrite(0 + display, LOW);
            shiftWrite(1 + display, LOW);
            shiftWrite(2 + display, LOW);
            shiftWrite(3 + display, HIGH);
            break;
        case 9:
            shiftWrite(0 + display, HIGH);
            shiftWrite(1 + display, LOW);
            shiftWrite(2 + display, LOW);
            shiftWrite(3 + display, HIGH);
            break;
    }
    updateDisplay();
}

void shiftWrite(int num, int state){
    switch(num){
        case 0:
            digitalWrite(16, state);
        break;
        case 1:
            digitalWrite(5, state);
        break;
        case 2:
            digitalWrite(4, state);
        break;
        case 3:
            digitalWrite(0, state);
        break;
        case 4:
            digitalWrite(2, state);
        break;
        case 5:
            digitalWrite(14, state);
        break;
        case 6:
            digitalWrite(12, state);
        break;
        case 7:
            digitalWrite(13, state);
        break;
        case 8:
            digitalWrite(15, state);
        break;
    }
}

void updateDisplay(){
    shiftWrite(LATCH_PIN, HIGH);
    shiftWrite(LATCH_PIN, LOW);
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
