#include "DigiKeyboard.h"

#define BUTTON_PIN 0  // Button on P0

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Enable internal pull-up resistor
}

void loop() {
    if (digitalRead(BUTTON_PIN) == LOW) {  // Button pressed
        DigiKeyboard.sendKeyStroke(0);  // Reset keystroke buffer
        DigiKeyboard.delay(500);

        // Open Notepad
        DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Win + R (Run)
        DigiKeyboard.delay(500);
        DigiKeyboard.print("notepad");
        DigiKeyboard.sendKeyStroke(KEY_ENTER);
        DigiKeyboard.delay(1000);

        // Type "Hello World!"
        DigiKeyboard.print("Hello World!");
        DigiKeyboard.sendKeyStroke(KEY_ENTER);

        // Wait until the button is released
        while (digitalRead(BUTTON_PIN) == LOW);
        DigiKeyboard.delay(500);
    }
}
