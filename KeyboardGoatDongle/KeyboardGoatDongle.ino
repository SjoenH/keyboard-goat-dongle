#include <Keyboard.h>

const int delayTime = 1000;  // Time between actions in milliseconds

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

    delay(2000);  // Wait for 2 seconds before starting

    // Open Slack
    openSlack();

    // Navigate to the correct channel and send the message
    navigateToChannel("stavanger");
    typeMessage(getRandomGoatMessage());

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
    // Command + Space to open Spotlight
    Keyboard.press(KEY_LEFT_GUI);  // Command key
    Keyboard.press(' ');
    delay(200);
    Keyboard.releaseAll();

    delay(500);  // Wait for Spotlight to open

    // Type 'Slack'
    Keyboard.print("Slack");
    delay(500);

    // Press Enter to open Slack
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();

    delay(2000);  // Wait for Slack to open
}

// Function to navigate to a specific Slack channel
void navigateToChannel(String channelName) {
    // Command + K to open the quick switcher
    Keyboard.press(KEY_LEFT_GUI);  // Command key
    Keyboard.press('k');
    delay(200);
    Keyboard.releaseAll();

    delay(500);  // Wait for the quick switcher to open

    // Type the channel name
    Keyboard.print(channelName);
    delay(500);

    // Press Enter to navigate to the channel
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();

    delay(1000);  // Wait for the channel to open
}

// Function to type a message with Norwegian keyboard layout
void typeMessage(String message) {
    for (int i = 0; i < message.length(); i++) {
        char c = message[i];
        switch (c) {
            case ':':
                Keyboard.press(KEY_LEFT_SHIFT);
                Keyboard.press('.');
                delay(10);
                Keyboard.releaseAll();
                break;
            case '!':
                Keyboard.press(KEY_LEFT_SHIFT);
                Keyboard.press('1');
                delay(10);
                Keyboard.releaseAll();
                break;
            default:
                Keyboard.print(c);
                break;
        }
        delay(100);  // Slight delay between each key press
    }
    Keyboard.press(KEY_RETURN);  // Press Enter to send the message
    delay(500);  // Wait for a short moment to ensure message is sent
    Keyboard.releaseAll();
}

// Function to close the Keyboard Setup Assistant on macOS
void closeKeyboardSetupAssistant() {
    // Command + W to close the window
    Keyboard.press(KEY_LEFT_GUI);  // Command key
    Keyboard.press('w');
    delay(200);
    Keyboard.releaseAll();

    delay(500);  // Wait for a short moment to ensure the window closes

    // Press Enter to confirm if any dialog appears
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
}