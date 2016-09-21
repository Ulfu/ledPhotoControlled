/*

 Dimms a light emitting diode(LED) connected to digital
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
const int buttonPin = 2;      // the number of the button pin

int ledValue = 0; //Current time to wait before next led blink
int minValue;
int maxValue;
int photoValue;
boolean buttonValue = (HIGH);

void setup() {
  // initialize the button pin as an input pullup:
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(photoResistor, INPUT);
  Serial.begin(9600);
  maxValue = analogRead(photoResistor);
  minValue = maxValue;
}

void loop() {
  buttonValue = digitalRead(buttonPin);
  photoValue = analogRead(photoResistor);
  if (!buttonValue) {
    if (photoValue < minValue){
      minValue = photoValue;
    }
    if (photoValue > maxValue){
      maxValue = photoValue;
    }
  }
  photoValue = constrain(photoValue, minValue, maxValue);
  ledValue = map((photoValue), minValue, maxValue, 0, 255); //Copy value to the variable
  analogWrite(ledPin, ledValue); //Write the values
  Serial.println(ledValue); //Pause the program for ledBlinkTime
  /*Serial.print(" min: " " max: " + maxValue);
  Serial.println(minValue);
  Serial.print(" max: ");
  Serial.println(maxValue);
  */
}
