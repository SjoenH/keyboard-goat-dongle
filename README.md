# Keyboard Goat Dongle
![Goat dongle](https://github.com/user-attachments/assets/974f2ad4-b35a-4387-8f85-b221f13cc5e3)

## Overview

The Keyboard Goat Dongle is an Arduino-based USB device that emulates a keyboard to send playful "goat" messages to a Slack channel. This project is designed for ease of development and customization using Arduino.

## Purpose

In many workplaces, users often forget to lock their computers when stepping away, potentially exposing sensitive information. The Keyboard Goat Dongle provides a light-hearted, automated reminder to reinforce good security habits. By sending humorous messages featuring a Goat emoji, this dongle aims to gently remind users to lock their screens, making the security practice both memorable and engaging.

## Features

- Emulates a USB keyboard using Arduino.
- Types out custom "goat" messages automatically.
- Selects a random message from a predefined list.
- Simple plug-and-play functionality.

## Requirements

- Arduino board (e.g., Arduino Leonardo, Micro, or any board with native USB support).
- Arduino IDE for programming.
- A computer with a USB port.
- Slack installed and configured on the computer.

## Installation

1. **Prepare the Arduino:**
   - Connect your Arduino board to your computer via USB.
   - Open the Arduino IDE and load the provided sketch from this repository.

2. **Upload the Sketch:**
   - Install the [Keyboard library](https://www.arduino.cc/en/Reference/Keyboard) if it's not already installed.
   - Upload the sketch to your Arduino board.

3. **Connect the Dongle:**
   - After uploading, unplug and replug the Arduino board into a USB port.
   - The dongle will start typing the pre-configured random messages in Slack.

## Configuration

You can customize the messages and the Slack channel by editing the Arduino sketch:

1. **Edit Messages:**
   - Open the Arduino sketch (`KeyboardGoatDongle.ino`).
   - Modify the `goatMessages` array with your desired messages.

2. **Change Target Channel:**
   - Update the `navigateToChannel("henry");` line in the `setup()` function to specify your desired Slack channel.

### Example Configuration

```cpp
// Array of absurd goat messages
String goatMessages[] = {
    "The Goat says Baaa! :goat: :party_parrot:",
    "Goat takeover! :goat: :tada:",
    "Baaa-rilliant! :goat: :sparkles:",
    "Goat's in charge! :goat: :robot:",
    "Moo-ving over, it's the Goat! :goat: :cow:",
    "Goat’s got the power! :goat: :zap:",
    "Baaa-ck at it again! :goat: :fire:",
    "The Goat’s here to party! :goat: :confetti_ball:",
    "Goat mode activated! :goat: :rocket:",
    "Goat's new mantra: Baaa! :goat: :smile:",
    "Here’s a baa for you! :goat: :wave:",
    "The Goat’s in control! :goat: :thumbsup:",
    "Baaa-rage incoming! :goat: :bomb:",
    "Goat's got the vibes! :goat: :sunglasses:",
    "Say hello to the Goat! :goat: :hello:"
};

// Target Slack channel
String channelName = "henry"; // Change this to your Slack channel name
```

## Usage

- **After Plugging In:** The dongle will begin typing random predefined goat messages in the specified Slack channel.
- **Customization:** Adjust the Arduino sketch to update messages and channel names as needed.

## Troubleshooting

- **Dongle Not Recognized:** Check that the Arduino board is properly connected and recognized by your computer.
- **Messages Not Typing:** Ensure the Arduino sketch is correctly uploaded and messages are properly configured.
- **Slack Channel Not Found:** Verify the channel name in the sketch matches exactly with the Slack channel name.

## Contributing

Contributions are welcome! To contribute to the project, please fork the repository and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
