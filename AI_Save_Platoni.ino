#include "HUSKYLENS.h"

HUSKYLENS huskylens;
int ledPin = 13; // LED connected to digital pin 13
int ledPin1 = 12;
int ledPin2 = 11;
int ledPin3 = 10;
int ledPin4 = 9;
int ledPin5 = 8;
int ledPin6 = 7;
int ledPin7 = 6;
int ledPin8 = 5;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    pinMode(ledPin, OUTPUT);
   
    // Initialize HuskyLens
    while (!huskylens.begin(Wire)) {
        Serial.println("Begin failed!");
        delay(100);
    }
}

void loop() {
    // Request data from HuskyLens
    if (!huskylens.request()) {
        Serial.println("Fail to request data!");
    } else {
        // Check if object is learned and available
        if (huskylens.isLearned()) {
            for (int i = 0; i < huskylens.countBlocks(); i++) {
                HUSKYLENSResult result = huskylens.getBlock(i);
               
                // If the object ID is 1, turn on the LED
                if (result.ID == 1) {
                    digitalWrite(ledPin, HIGH);
                    digitalWrite(ledPin1, HIGH);
                    digitalWrite(ledPin2, HIGH);
                    digitalWrite(ledPin3, HIGH);
                    digitalWrite(ledPin4, HIGH);
                    digitalWrite(ledPin5, HIGH);
                    digitalWrite(ledPin6, HIGH);
                    digitalWrite(ledPin7, HIGH);
                    digitalWrite(ledPin8, HIGH);
                    Serial.println("Object 1 Detected - LED ON");
                } else {
                    digitalWrite(ledPin, LOW);
                    digitalWrite(ledPin1, LOW);
                    digitalWrite(ledPin2, LOW);
                    digitalWrite(ledPin3, LOW);
                    digitalWrite(ledPin4, LOW);
                    digitalWrite(ledPin5, LOW);
                    digitalWrite(ledPin6, LOW);
                    digitalWrite(ledPin7, LOW);
                    digitalWrite(ledPin8, LOW);

                }
            }
        }
    }
    delay(100); // Small delay to improve stability
}