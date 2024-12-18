/*
  Photoshop Quick Launch Example for AltController Library
  
  Provides quick launch and basic controls for Photoshop:
  - Windows Search (Windows + 'photoshop' + Enter) on pin 2
  - Mac Spotlight (Command + Space) on pin 3
  - Enter key on pin 4
  - Type 'photoshop' on pin 5
  - New Document (Ctrl+N) on pin 6
  
  Note: Windows key is KEY_LEFT_GUI
        Mac Command key is also KEY_LEFT_GUI
  
  Connection:
  - Connect buttons between the specified pins and ground
  - Internal pullup resistors are used, no external resistors needed
*/

#include <AltController.h>

// Pin assignments
const int WIN_SEARCH_PIN = 2;
const int MAC_SPOTLIGHT_PIN = 3;
const int ENTER_PIN = 4;
const int TYPE_PS_PIN = 5;
const int NEW_DOC_PIN = 6;

// Timing configuration (in milliseconds)
const int MACRO_TIME = 100;    // For key combinations
const int KEY_TIME = 50;       // For single keys
const int TYPE_TIME = 150;     // For text typing

AltController controller;

void setup() {
    // Windows key (GUI key)
    controller.addKeyPress(WIN_SEARCH_PIN, KEY_LEFT_GUI, MACRO_TIME);
    
    // Mac Spotlight (Command + Space)
    controller.addMacro(MAC_SPOTLIGHT_PIN, {KEY_LEFT_GUI, ' '}, MACRO_TIME);
    
    // Enter key
    controller.addKeyRelease(ENTER_PIN, KEY_RETURN, KEY_TIME);
    
    // Type "photoshop"
    controller.addPrint(TYPE_PS_PIN, "photoshop", TYPE_TIME);
    
    // New Document shortcut
    controller.addMacro(NEW_DOC_PIN, {KEY_LEFT_CTRL, 'n'}, MACRO_TIME);
}

void loop() {
    controller.update();
}

/* Usage Instructions:

   For Windows:
   1. Press Windows key (pin 2)
   2. Press Type PS (pin 5)
   3. Press Enter (pin 4)

   For Mac:
   1. Press Mac Spotlight (pin 3)
   2. Press Type PS (pin 5)
   3. Press Enter (pin 4)

   After Photoshop opens:
   - Press New Doc (pin 6) to create new document
*/