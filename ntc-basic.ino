/**
  Basic NTC Thermistor demo
  https://wokwi.com/arduino/projects/299330254810382858

  Assumes a 10K@25℃ NTC thermistor connected in series with a 10K resistor.

  Copyright (C) 2021, Uri Shaked
*/

const float BETA = 3950; // should match the Beta Coefficient of the thermistor
#define REDLED 13
#define YELLOWLED 12
#define GREENLED 8

void setup() {
  Serial.begin(9600);
  pinMode(REDLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
}

void loop() {
  int analogValue = analogRead(A0);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" ℃");

  // lit down all the LED lights
  digitalWrite(GREENLED, LOW);
  digitalWrite(YELLOWLED, LOW);
  digitalWrite(REDLED, LOW);

  if (celsius < 30) {
    // lit up the green LED
    digitalWrite(GREENLED, HIGH);
  } else if (celsius <= 80) {
    // lit up the yellow LED
    digitalWrite(YELLOWLED, HIGH);
  } else {
    // lit up the red LED
    digitalWrite(REDLED, HIGH);
  }

  delay(1000);
}
