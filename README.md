# Keyboard Goat Dongle

## Overview

The Keyboard Goat Dongle is an Arduino-based USB device that emulates a keyboard to send playful "goat" messages and change the desktop background of the connected computer. This project is designed for ease of development and customization using Arduino.

## Features

- Emulates a USB keyboard using Arduino.
- Types out custom "goat" messages automatically.
- Changes the desktop background to a goat-themed image (compatible with Windows and macOS).
- Simple plug-and-play functionality.

## Requirements

- Arduino board (e.g., Arduino Leonardo, Micro, or any board with native USB support).
- Arduino IDE for programming.
- A computer with a USB port.
- Compatible with Windows or macOS for background change functionality.

## Installation

1. **Prepare the Arduino:**
   - Connect your Arduino board to your computer via USB.
   - Open the Arduino IDE and load the provided sketch from this repository.

2. **Upload the Sketch:**
   - Install the [Keyboard library](https://www.arduino.cc/en/Reference/Keyboard) if it's not already installed.
   - Upload the sketch to your Arduino board.

3. **Connect the Dongle:**
   - After uploading, unplug and replug the Arduino board into a USB port.
   - The dongle will start typing the pre-configured messages and changing the desktop background.

## Configuration

You can customize the messages and the desktop background by editing the Arduino sketch:

1. **Edit Messages:**
   - Open the Arduino sketch (`KeyboardGoatDongle.ino`).
   - Modify the `goatMessages` array with your desired messages.

2. **Change Desktop Background:**
   - Update the `backgroundImagePath` variable in the sketch to point to the goat-themed image. This feature works for both Windows and macOS.

### Example Configuration

```cpp
// Messages to be typed out by the dongle
String goatMessages[] = {
  "Hello from the Goat! :goat:",
  "Moo-ve over, here comes the goat! :goat:"
};

// Path to the goat-themed image (Windows or macOS)
String backgroundImagePath = "C:\\path\\to\\goat-image.jpg"; // Windows
// String backgroundImagePath = "/path/to/goat-image.jpg"; // macOS
```

## Usage

- **After Plugging In:** The dongle will begin typing the predefined messages and change the desktop background automatically.
- **Customization:** Adjust the Arduino sketch to update messages and background images as needed.

## Troubleshooting

- **Dongle Not Recognized:** Check that the Arduino board is properly connected and recognized by your computer.
- **Messages Not Typing:** Ensure the Arduino sketch is correctly uploaded and messages are properly configured.
- **Desktop Background Not Changing:** Verify the image path in the sketch and confirm that the file is accessible.

## Contributing

Contributions are welcome! To contribute to the project, please fork the repository and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
