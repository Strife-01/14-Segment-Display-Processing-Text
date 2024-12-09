# 14-Segment Display Processing Text

![C Programming Language](https://raw.githubusercontent.com/github/explore/main/topics/c/c.png)
![Microchip Logo](https://upload.wikimedia.org/wikipedia/commons/c/ca/Microchip-Logo.svg)

This project implements a text-processing system for a **14-segment alphanumeric display**, controlled by the **PIC18F47Q10** microcontroller. It provides an interface to input ASCII text, which is displayed on the 14-segment display in a rolling fashion from **right to left**.

---

## Features

- **Microcontroller**: PIC18F47Q10
- **Display**: 14-segment alphanumeric LED
- **Text Display**: Supports scrolling text from right to left
- **Interface**: Accepts ASCII text input via UART or another communication protocol
- **Encoding**: Maps ASCII characters to their corresponding 14-segment display codes
- **Rolling Effect**: Smooth scrolling of text across the display

---

## Hardware Overview

The system uses a **14-segment alphanumeric display** driven by the PIC18F47Q10 microcontroller. Input text is processed and encoded into 14-segment display signals. The rolling effect is implemented through a time-based scrolling mechanism.

### Key Components

- **14-Segment Display**:
  - Displays alphanumeric characters and some special symbols.
  - Connected to the microcontroller via GPIO pins or a dedicated driver IC.

- **Text Input Interface**:
  - Text is sent via UART or a similar protocol.
  - The system processes the input and prepares it for display.

- **Rolling Text Implementation**:
  - Characters are shifted from right to left, creating a scrolling effect.
  - Speed of scrolling can be adjusted in the firmware.

---

## Software

The firmware is written in **C** using MPLAB X IDE with the XC8 compiler. It handles:

- **Text Parsing**: Reads ASCII text input and stores it in a buffer.
- **Character Encoding**: Converts ASCII characters into 14-segment control codes.
- **Rolling Text Display**: Implements a timed scrolling mechanism for smooth text transitions.
- **UART Communication**: Accepts text input from an external source.

---

## Getting Started

### Prerequisites

- **MPLAB X IDE**
- **XC8 Compiler**
- **PICkit 4 or compatible programmer**
- **A custom board presenting the chip, 14-Segment Alphanumeric Display and additional functionality such as serial or wifi for data transfer**

---

### Setup

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Strife-01/14-Segment-Display-Processing-Text.git
   ```
   
2. **Open the Project**:
   - Launch **MPLAB X IDE**.
   - Navigate to `File` > `Open Project` and select the cloned repository.

3. **Configure the Project**:
   - Ensure the **PIC18F47Q10** microcontroller is selected.
   - Verify inclusion of necessary libraries and dependencies.

4. **Connect the Hardware**:
   - Connect the **14-segment display** to the PIC18F47Q10 as per the wiring diagram included in the project directory.
   - Set up UART or another input interface to send ASCII text.

5. **Build and Program**:
   - Build the project using the XC8 compiler.
   - Upload the program to the PIC18F47Q10 using PICkit 4 or another compatible programmer.

---

## Usage

1. **Power the Circuit**:
   - Use a 5V power source to power the microcontroller and the display.

2. **Send Text Input**:
   - Use the UART interface to send ASCII text to the microcontroller.

3. **Text Scrolling**:
   - The input text will scroll from right to left across the 14-segment display.

4. **Modify Behavior**:
   - Adjust the scrolling speed or add additional features by modifying the source code.

---

## Project Showcase

[![14-Segment Display Showcase](https://youtu.be/5-tJlkCdAZc)](https://youtu.be/5-tJlkCdAZc)

*Click on the image above to watch a quick demo of the project.*

---

## Contributing

Contributions are welcome! If you have improvements or additional features to share, please fork the repository, create a new branch for your feature or bug fix, and submit a pull request. Ensure your code adheres to the project's coding standards and includes appropriate documentation.

---

## License

This project is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute the code, provided proper attribution is given.
