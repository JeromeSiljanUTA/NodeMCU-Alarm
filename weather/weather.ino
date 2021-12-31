// Libraries
#include <OpenWeatherOneCall.h>
#include <ESP8266WiFi.h>
#include <string.h>
#include <time.h>
#include "Display.h"

// WiFi Setup
const char *ssid = "Frontier1312";
const char *password = "2891547465";

// NTP Setup
#define MY_NTP_SERVER "at.pool.ntp"
#define MY_TZ "CST6CDT"

tm timeinfo;
time_t now;

// initializing displays
Display disp[] = {Display(5, 4, 0, 2), Display(14, 12, 13, 15)};

WiFiClient client;

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
    setWifi();
    configTime(MY_TZ, MY_NTP_SERVER);
}


void loop() {
    getSecond();
} 

void printNum(int num, Display disp[2]){
    int tens = num/10;
    int ones = num%10;
    disp[0].writeNum(tens);
    disp[1].writeNum(ones);
}

void setWifi(){
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(WiFi.localIP());
}

void getSecond(){
    time(&now);
    localtime_r(&now, &timeinfo);
    printNum(timeinfo.tm_sec, disp);
    updateDisplay();
}

void updateDisplay(){
    digitalWrite(LATCH_PIN, HIGH);
    digitalWrite(LATCH_PIN, LOW);
}
