#include <Arduino.h>
#include "AudioFileSourcePROGMEM.h"
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2SNoDAC.h"
#include "viola.h"

#define BLYNK_TEMPLATE_ID "TMPLxxgZsTtL"
#define BLYNK_DEVICE_NAME "ESP8266"
#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial  
#define APP_DEBUG

// #define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
// #define USE_WITTY_CLOUD_BOARD
// #define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
#include <SimpleTimer.h>
SimpleTimer timer;

AudioGeneratorWAV *wav;
AudioFileSourcePROGMEM *file;
AudioOutputI2SNoDAC *out;

int DataMQ2 = 0; 

void setup(){
  Serial.begin(115200);
  delay(100);
  Serial.println("Smoke Detected Starting!");
  timer.setInterval(1000L, getSendData);
  BlynkEdgent.begin();
}

void loop() {
  timer.run();
  BlynkEdgent.run();
}

void getSendData() {

  audioLogger = &Serial;
  file = new AudioFileSourcePROGMEM( viola, sizeof(viola) );
  out = new AudioOutputI2SNoDAC();
  wav = new AudioGeneratorWAV();
  wav->begin(file, out);

  // DataMQ2 = analogRead(A0); 
  // Serial.print("DataMQ2 : ");
  // Serial.println(DataMQ2);
  // Blynk.virtualWrite(V0, DataMQ2);

  // if ( DataMQ2 >= 400 ) {
  //   Blynk.logEvent("gas_smoke_alert","DETECTED LPG/SMOKE!");
  //   Serial.println("DataMQ2 : Smoke Detected!");
  //   delay(1000);
    // audioLogger = &Serial;
    // file = new AudioFileSourcePROGMEM( viola, sizeof(viola) );
    // out = new AudioOutputI2SNoDAC();
    // wav = new AudioGeneratorWAV();
    // wav->begin(file, out);
  // }
}
