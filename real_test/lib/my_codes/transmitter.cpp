#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(2000, 15, 2);
int i = 0;

void setup() {
    Serial.begin(115200);
    delay(5000);
    Serial.println("RF Transmitter Init");

    if (!driver.init()) {
        Serial.println("init failed");
    }
}

void loop() {
    const char *msg = "Sending continuously...";
    driver.send((uint8_t *)msg, strlen(msg) + 1);
    driver.waitPacketSent();

    Serial.println("Message sent!");
    delay(1000);
}
