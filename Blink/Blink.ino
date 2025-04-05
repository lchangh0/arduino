/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

#define LED_R 10
#define LED_Y 11
#define LED_G 12
#define LED_B 13


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_R, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  Serial.begin(115200);
  Serial.println("Start");
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_B, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
  digitalWrite(LED_B, LOW);   // turn the LED off by making the voltage LOW
  delay(500);                      // wait for a second

  uint8_t portB_val = PINB;
  uint8_t portC_val = PINC;
  uint8_t portD_val = PIND;
  Serial.print(", portB:0x");
  Serial.print(portB_val, HEX);
  Serial.print(", portC:0x");
  Serial.print(portC_val, HEX);
  Serial.print(", portD:0x");
  Serial.print(portD_val, HEX);
  Serial.println("");

}
