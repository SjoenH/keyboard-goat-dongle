#include <Keyboard.h>

// Channel name to post to
const String CHANNEL_NAME = "stavanger";

// Constants for timing and keyboard shortcuts
const int OPEN_SLACK_DELAY = 2000;  // Delay for opening Slack
const int APP_LAUNCH_DELAY = 500;   // Delay for app launcher or Spotlight
const int MESSAGE_DELAY = 500;      // Delay for message dialog
const int KEY_PRESS_DELAY = 100;    // Delay between key presses
const int SHORT_DELAY = 200;        // Short delay for UI interactions

// Array of absurd goat messages
String goatMessages[] = {
  "The Goat says Baaa! :goat: :party_parrot:",
  "Goat takeover! :goat: :tada:",
  "Baaa-rilliant! :goat: :sparkles:",
  "Goat's in charge! :goat: :robot:",
  "Moo-ving over, it's the Goat! :goat: :cow:",
  "Goat's got the power! :goat: :zap:",
  "Baaa-ck at it again! :goat: :fire:",
  "The Goat's here to party! :goat: :confetti_ball:",
  "Goat mode activated! :goat: :rocket:",
  "Goat's new mantra: Baaa! :goat: :smile:",
  "Here's a baa for you! :goat: :wave:",
  "The Goat's in control! :goat: :thumbsup:",
  "Baaa-rage incoming! :goat: :bomb:",
  "Goat's got the vibes! :goat: :sunglasses:",
  "Say hello to the Goat! :goat: :hello:"
};

const int numMessages = sizeof(goatMessages) / sizeof(goatMessages[0]);

void setup() {
  // Seed the random number generator
  randomSeed(analogRead(0));

  // Start Keyboard library
  Keyboard.begin();

  delay(OPEN_SLACK_DELAY);  // Wait for 2 seconds before starting

  // Open Slack
  openSlack();

  // Navigate to the correct channel and send the message
  navigateToChannel(CHANNEL_NAME);
  typeMessage(getRandomGoatMessage());

  // Change desktop background
  changeDesktopBackground();

  // End Keyboard library
  Keyboard.end();
}

void loop() {
  // No repeated actions needed
}

// Function to get a random goat message
String getRandomGoatMessage() {
  int index = random(numMessages);
  return goatMessages[index];
}

// Function to open Slack
void openSlack() {
  // Open Slack on both Windows and Mac by simulating key presses

  // For Windows: Press the Windows key to open the Start Menu
  Keyboard.press(KEY_LEFT_GUI);  // Windows key
  delay(SHORT_DELAY);
  Keyboard.releaseAll();

  // For Mac: Press Command + Space to open Spotlight search
  Keyboard.press(KEY_LEFT_GUI);  // Command key
  Keyboard.press(' ');           // Space key
  delay(SHORT_DELAY);
  Keyboard.releaseAll();

  delay(APP_LAUNCH_DELAY);  // Wait for the app launcher or Spotlight to be ready

  // Type "Slack" to search for the application
  Keyboard.print("Slack");
  delay(SHORT_DELAY);

  // Press Enter to launch Slack
  Keyboard.press(KEY_RETURN);
  delay(SHORT_DELAY);
  Keyboard.releaseAll();
  delay(OPEN_SLACK_DELAY);  // Wait for Slack to open
}

// Function to navigate to a specific Slack channel
void navigateToChannel(String channelName) {
  // Open a new message dialog in Slack
  Keyboard.print("/new message");  // Type the command to start a new message
  Keyboard.press(KEY_RETURN);      // Press Enter to execute the command
  delay(MESSAGE_DELAY);            // Wait for the new message dialog to open
  Keyboard.releaseAll();           // Ensure no keys are pressed after sending the command

  // Type the channel name
  Keyboard.print(channelName);
  delay(SHORT_DELAY);             // Wait to ensure the channel name is typed correctly
  Keyboard.releaseAll();         // Ensure no keys are pressed after typing the channel name

  // Press Enter to send the message (navigate to the channel)
  Keyboard.press(KEY_RETURN);
  delay(MESSAGE_DELAY);          // Wait for Slack to navigate to the channel
  Keyboard.releaseAll();        // Ensure no keys are pressed after sending the message
}

// Function to type a message with Norwegian keyboard layout
void typeMessage(String message) {
  for (int i = 0; i < message.length(); i++) {
    char c = message[i];
    switch (c) {
      case ':':
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('.');
        delay(KEY_PRESS_DELAY);
        Keyboard.releaseAll();
        break;
      case '!':
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('1');
        delay(KEY_PRESS_DELAY);
        Keyboard.releaseAll();
        break;
      default:
        Keyboard.print(c);
        break;
    }
    delay(KEY_PRESS_DELAY);  // Slight delay between each key press
  }
  Keyboard.press(KEY_RETURN);  // Press Enter to send the message
  delay(MESSAGE_DELAY);        // Wait for a short moment to ensure message is sent
  Keyboard.releaseAll();
}

// Function to close the Keyboard Setup Assistant on macOS
void closeKeyboardSetupAssistant() {
  // Command + W to close the window
  Keyboard.press(KEY_LEFT_GUI);  // Command key
  Keyboard.press('w');
  delay(SHORT_DELAY);
  Keyboard.releaseAll();

  delay(SHORT_DELAY);  // Wait for a short moment to ensure the window closes

  // Press Enter to confirm if any dialog appears
  Keyboard.press(KEY_RETURN);
  delay(SHORT_DELAY);
  Keyboard.releaseAll();
}

// Function to change desktop background to goat image
void changeDesktopBackground() {
  // Open Terminal
  Keyboard.press(KEY_LEFT_GUI);  // Command key
  Keyboard.press(' ');           // Space key
  delay(SHORT_DELAY);
  Keyboard.releaseAll();

  delay(APP_LAUNCH_DELAY);
  Keyboard.print("Terminal");
  delay(SHORT_DELAY);
  Keyboard.press(KEY_RETURN);
  delay(SHORT_DELAY);
  Keyboard.releaseAll();

  delay(OPEN_SLACK_DELAY);  // Wait for Terminal to open

  // Type and execute the command
  Keyboard.print("wget -O /tmp/goat.jpg https://wallpapercave.com/wp/wp9348729.jpg && \\");
  Keyboard.press(KEY_RETURN);
  delay(SHORT_DELAY);
  Keyboard.releaseAll();

  Keyboard.print("osascript -e 'tell application \"System Events\" to set picture of current desktop to \"/tmp/goat.jpg\"'");
  Keyboard.press(KEY_RETURN);
  delay(SHORT_DELAY);
  Keyboard.releaseAll();

  // Wait for download to complete
  delay(1000);

  // Press Enter to confirm setting the background
  Keyboard.press(KEY_RETURN);
  delay(SHORT_DELAY);
  Keyboard.releaseAll();

  // Close Terminal
  Keyboard.press(KEY_LEFT_GUI);  // Command key
  Keyboard.press('w');
  delay(SHORT_DELAY);
  Keyboard.releaseAll();
}