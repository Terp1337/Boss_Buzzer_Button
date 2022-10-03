# Boss_Buzzer_Button
A master switch for the boss to simply mute the meeting

## Content

  - [Motivation](#motivation)
  - [Function Description](#function-description)
  - [Hardware Requirement](#hardware-requirement)

### Motivation
This switch is a PoC. It is intended to show how risky unauthorized hardware on official computers can be.


### Function Description
In the first function, it mutes the teams meeting as described.

If the switch is pressed for more than 1 sec. it minimizes all open windows and starts the browser in kiosk mode. Here an external website with a GIF is called.

If the button is pressed for more than 3 seconds, it minimizes all open windows and starts the browser in kiosk mode. This time a MP4 file is started in full screen. 


### Hardware Requirement
In this project a Digispark 2.0 with a Tiny85 was used.
For the switch a simple pushbutton without resistor was connected. After programming the Digispark is connected to the computer with a USB extension cable. 
