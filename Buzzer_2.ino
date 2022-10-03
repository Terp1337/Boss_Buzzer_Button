/* 
Fun boss button to demonstrate the risk of unauthorized and untested hardware :-)
Tested on Windows 10 v. 21H2
Version 2.01
*/ 

#include "DigiKeyboardDe.h"
#define KEY_Print                0x46 
#define KEY_M                    0x10
#define KEY_T                    0x54
#define KEY_R                    0x15
#define VK_RETURN                0x0d                                          // Return Key
#define VK_MENU	                 0x12                                          // ALT Key
#define KEY_RIGHTCTRL            0xe4
#define KEY_RIGHTSHIFT           0xe5
#define VK_SPACE                 0x2c                                          // Space Key        0x20
#define VK_LWIN                  0xe3                                          // Left Windows Key 0x5b
#define MOD_GUI_LEFT             0xe008                                        // Left Windows Key                                      

                                                                               //We need to track how long the momentary pushbutton is held in order to execute different commands
float pressLength_milliSeconds = 0;                                            // This value will be recorded in seconds

                                                                               // Function for the button routine
int functionButtonMP4();
int functionButtonGIF();    
int functionButtonTeams();
int functionMinimize();                 

const byte SwitchPin       = 2;                                                // PinNumber (P0) is defined as a constant to optimize memory space.
const byte BuildInLed      = 1;                                                // Buildin LED
byte SwitchBufferState     = HIGH;                                             // Declaration value for key state


void setup() 
{
  pinMode(SwitchPin, INPUT_PULLUP);                                            // Pin 0 des DigiSparks wird auf Digitaleingang mit internem Pullup definiert.
  digitalWrite (BuildInLed,LOW);                                               // Interne LED ausschalten
  Serial.begin(9600);                                                          // Startet den seriellen Monitor zum debuggen
}

void loop() 
{
 if (digitalRead(SwitchPin)== LOW  &&  SwitchBufferState == HIGH ){
    while (digitalRead(SwitchPin) == LOW){
      delay(100);
      pressLength_milliSeconds = pressLength_milliSeconds + 100;
    }
    if (pressLength_milliSeconds >= 3000){
      functionButtonMP4();
    }
    if (pressLength_milliSeconds >= 2000 && pressLength_milliSeconds <= 2999){
      functionButtonGIF();
    }
    if (pressLength_milliSeconds <= 1999){
      functionButtonTeams();
    }    

    digitalWrite (BuildInLed,HIGH);                                            // Interne LED einschalten
    delay(80);                                                                 // debouncing button 80 ms
    SwitchBufferState = LOW;      
    pressLength_milliSeconds = 0;
  }

  if ((digitalRead(SwitchPin)== HIGH &&  SwitchBufferState == LOW)){
    digitalWrite (BuildInLed,LOW);                                             // Interne LED ausschalten
    delay(80);                                                                 // debouncing button 80 ms
    SwitchBufferState = HIGH;
  }
  delay(100);

}

int functionButtonGIF(){
  functionMinimize();
  DigiKeyboardDe.println("msedge.exe --kiosk https://bit.ly/3rj0BjC --edge-kiosk-type=fullscreen"); // anon.MP4 single video
  return 1;
}


int functionButtonMP4(){
  functionMinimize();
  DigiKeyboardDe.println("msedge.exe --kiosk https://bit.ly/3rj13hv --edge-kiosk-type=fullscreen"); // anon.GIF loop video
  return 2;
}


int functionButtonTeams(){
  delay(80);
  // Simulation of Ctrl + Shift + M for mute in Teams
  DigiKeyboardDe.sendKeyStroke(KEY_M,MOD_CONTROL_LEFT|MOD_SHIFT_LEFT); 
  return 3; 
}

int functionMinimize(){
  //Windows + M to minimize all windows
  DigiKeyboardDe.sendKeyStroke(KEY_M,MOD_GUI_LEFT);
  delay(50);
  //Windows + R to start run window
  DigiKeyboardDe.sendKeyStroke(KEY_R , MOD_GUI_LEFT);
  DigiKeyboardDe.delay(250); 
}



