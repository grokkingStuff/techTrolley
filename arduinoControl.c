#include <KeyboardController.h>


int solenoidPin[6]={5,6,7,8,9,10};       // Positions on the board that connects solenoid 0 to solenoid[0]'s pin.
float triggerTime[6]={0.04,4,6,7,8,9};   // Consecutive time between triggers. in seconds


//Keyboard settings

// use this option for OSX:
char ctrlKey = KEY_LEFT_GUI;
// use this option for Windows and Linux:
//  char ctrlKey = KEY_LEFT_CTRL;  

// Initialize USB Controller
USBHost usb;

// Attach Keyboard controller to USB
KeyboardController keyboard(usb);

// make all the pin modes!
// takes in array of pins and converts them to pin modes and stores it in a global variable for everyone's use. (bad code but who cares rn.)

void makePinModes(int* pinArray)
  {
    for (int i=0; i < sizeof(pinArray); i++ ) {
      pinMode(pinArray[i],OUTPUT);
    }
  }

void triggerPin(int* pinArray, int index)
  {
    digitalWrite(pinArray[index],HIGH);
  }

void stopPins(int* pinArray)
{
  for (int i=0; i < sizeof(pinArray); i++ ) {
    digitalWrite(pinArray[index],LOW);
  }
}

void startTriggering() {
  Serial.print("Hi there! Please ensure the following safety procedures take place before you trigger the solenoids");
  Serial.print("    No one is touching anything connected to your lead acid battery or capacitors.");
  Serial.print("    Your lead-acid battery is not discharging anymore");
  Serial.print("    Your capacitors are fully charged and ready to discharge safely");
  Serial.print("    Your pod is properly placed in the track.");
  Serial.print("    There are sufficient retardation towels at the end. Make sure they're folded");
  Serial.print("    Pressed y for triggering:  ");
  char keyPressed
  keyPressed = keyboard.getKey();
  while (keyPressed != 'y')
    {
      Serial.print("Pressed y for triggering:  ");
      keyPressed = keyboard.getKey();
    }
  }

void setup()
{
  startTriggering();
  makePinModes(solenoidPin);
  for (int i=0; i < sizeof(pinArray); i++ ) {
    triggerPin(i);
    delay(triggerTime[i]*1000)      // Converts seconds to milliseconds
  }
  stopPins(solenoidPin);
}


void loop()
{



}

