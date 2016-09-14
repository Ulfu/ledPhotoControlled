/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 Pullupp-switch

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.

 This example code is in the public domain.
 */

// constants won't change. They're used here to
// set pin numbers:
const int photoResistor = 0;     // the number of the pushbutton pin
const int ledPin = 3;      // the number of the LED pin

int ledValue = 0; //Current time to wait before next led blink

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(photoResistor, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value, write the opposite value to ledPin:
  ledValue = map(analogRead(photoResistor), 0, 1023, 0, 255); //Copy value to the variable
  analogWrite(ledPin, ledValue); //Write the values
  Serial.println(ledValue); //Pause the program for ledBlinkTime
}
