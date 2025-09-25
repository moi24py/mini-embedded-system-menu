# Mini menu

This project is designed to practice and demonstrate the use of various input handling functions in C, specifically focusing on `fgets`, `strtol`, `read`, and buffer input management.

## Overview

The program presents a simple menu to the user, allowing them to choose between reading numbers, reading sentences, or exiting the program. It showcases how to handle user input effectively and process it accordingly.

## Features

- **Menu Display**: The program displays a menu with three options:
  1. Read numbers from standard input.
  2. Read sentences from standard input.
  3. Exit the program.

- **Input Handling**:
  - For option 1, the program reads raw input using the `read()` function and processes it to extract and print only the numeric characters.
  - For option 2, it uses `fgets()` to read a complete sentence and then displays it back to the user.

- **Error Handling**: The program includes error handling for input reading and conversion processes, ensuring robustness.

## Code Explanation

### Functions

- **`print_menu()`**: Displays the menu options to the user.
  
- **`choice()`**: Reads the user's choice from standard input, converts it from a string to a long integer using `strtol`, and checks for conversion errors.

### Main Logic

1. The program starts by displaying the menu.
2. It waits for the user to make a choice.
3. Based on the user's choice, it either:
   - Reads and processes numbers.
   - Reads and displays a sentence.
   - Exits the program.

### Example Usage

To run the program, compile it using a C compiler and execute the resulting binary. Follow the prompts to enter your choice and input.

```bash
gcc main.c -o main
./main
```

## Learning Objectives
This project serves as a practical exercise in:
- Using fgets for reading strings safely.
- Utilizing strtol for converting strings to numbers with error checking.
- Implementing low-level input reading with read().
- Managing buffer input effectively.
