/*
Gabriel & Jess
5 May 2026

Create a light-based distance sensor using an LED and LDR (Light-dependent resistor).

Cool, bruh.

References:
1. https://store-usa.arduino.cc/products/arduino-nano
    1. https://content.arduino.cc/assets/Pinout-NANO_latest.pdf
1. https://docs.arduino.cc/language-reference/

Notes:
V = IR
R = V/I = (5-3)V/0.016A = 125 Ohms

Diagram:
LED:
5V---125 Ohm Resistor---(+)LED(-)---GND
LDR voltage divider:
5V---LDR---2.2k---GND
         |
         A0

*/

void setup()
{
    // put your setup code here, to run once:
    pinMode(A0, INPUT);
    Serial.begin(115200);
}

void loop()
{
    constexpr float CALIBRATED_VIN = 4.66; // Measured voltage from 5V pin on Arduino Nano

    uint16_t light_sensor_value = analogRead(A0);
    // Convert to volts
    float light_sensor_v = light_sensor_value * (CALIBRATED_VIN / 1024.0);

    // Print the raw analog reading values
    // Serial.print("0,");
    // Serial.print(light_sensor_value);
    // Serial.print(",1024\n");

    // Print the voltage values
    // Serial.print("0,");
    // Serial.print(light_sensor_v);
    // Serial.print(",");
    // Serial.print(CALIBRATED_VIN);
    // Serial.print(",");

    // Map voltage to distance
    constexpr float FROM_LOW_V = 1.75;
    constexpr float FROM_HIGH_V = 3.20;
    constexpr float TO_LOW_DIST_CM = 0.0;
    constexpr float TO_HIGH_DIST_CM = 10.0;
    // Linear interpolation formula (inverted: high voltage = close, low voltage = far)
    float distance_cm = (light_sensor_v - FROM_LOW_V)
        * (TO_LOW_DIST_CM - TO_HIGH_DIST_CM)
        / (FROM_HIGH_V - FROM_LOW_V)
        + TO_HIGH_DIST_CM;
    distance_cm = constrain(distance_cm, TO_LOW_DIST_CM, TO_HIGH_DIST_CM);

    // Print the distance values
    Serial.print("0,");
    Serial.print(distance_cm);
    Serial.print(",");
    Serial.print(TO_HIGH_DIST_CM);
    Serial.print("\n");

    delay(100);
}

