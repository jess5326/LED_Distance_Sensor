A test program with Gabriel Staples to turn a regular white LED and LDR photoresistor into a short-range distance sensor.


# Goal

Create a light-based distance sensor using an LED and LDR (Light-dependent resistor).

Cool, bruh.


# References
1. https://store-usa.arduino.cc/products/arduino-nano
    1. https://content.arduino.cc/assets/Pinout-NANO_latest.pdf
1. https://docs.arduino.cc/language-reference/


# Notes
V = IR  
R = V/I = (5-3)V/0.016A = 125 Ohms


# Diagram

```text
LED:
5V---125 Ohm Resistor---(+)LED(-)---GND
LDR voltage divider:
5V---LDR---2.2k---GND
         |
         A0
```
