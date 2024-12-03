#include <Servo.h>

Servo myServo;

int pos = 0;
const int buttonPin = 2;
int buttonState = 0;
int state = LOW;
int previous = LOW;
unsigned long debounce = 1000;
unsigned long time = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  myServo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  
  if(buttonState == HIGH && previous == LOW && millis() - time > debounce) { // detects if button was pressed and after a cooldown of 1 second
    if(state == HIGH) { //lines 25-30 switches the state of the button to the opposite of what it was
      state = LOW;
    }
    else {
      state = HIGH;
    }
    time = millis();//sets time to current time to prep for when it loops
  }
  if(state == HIGH) { //write the state to servo
    myServo.write(45);
  }
  else {
    myServo.write(0);
  }
  previous = buttonState; // 
  // Serial.print("previous : ", previous);
}
