#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(2000, 15, 2);
int i = 0;

void setup() {
  Serial.begin(115200);
  delay(5000);
  
  if (!driver.init()) {
    Serial.println("RF driver initialization failed");
  } else {
    Serial.println("RF driver initialized successfully. Waiting for message...");
  }
  
}

void loop() {
//   if (driver.available()) {
uint8_t buf[20];
uint8_t buflen = sizeof(buf);
if (driver.recv(buf, &buflen)) {
    Serial.print("Received Message (Length ");
    Serial.print(buflen);
    Serial.print("): ");
    Serial.println((char*)buf);
}
//   }
  delay(100); 
}
