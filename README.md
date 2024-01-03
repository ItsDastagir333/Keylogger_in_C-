# Keylogger in C++

This repository contains the source code for a simple keylogger written in C++. The keylogger, when executed, records keystrokes and stores them into a file named `Data.txt`. This project is intended for educational purposes and should be used responsibly.

## Disclaimer

Keyloggers can be potent tools for monitoring and logging keyboard input. However, they can also be used for malicious purposes. This code is provided for educational purposes only. The author is not responsible for any misuse of this keylogger. It is the end user's responsibility to comply with all applicable local, state, and federal laws.

## Features

- Records all keystrokes and saves them to a file (`Data.txt`).
- Ability to record special keys (like Shift, Ctrl, Enter, etc.).
- Option to hide the console window to run the keylogger in the background (currently disabled by default).

## Usage

1. **Compile the Code:**
   To use the keylogger, you must first compile the C++ code. This requires a C++ compiler like GCC or a C++ IDE like Visual Studio or Code::Blocks.

2. **Run the Keylogger:**
   - Directly run the compiled executable. By default, the keylogger window will be visible.
   - To run the keylogger in stealth mode, uncomment the line `// hide();` in the `main()` function and recompile the code.

3. **Check Output:**
   The keystrokes will be saved in `Data.txt` in the same directory as your executable. Open this file to view the logged data.

## Code Structure

- **`main()` Function:**
  - Starts the keylogger (visible mode by default).
  - Call `hide()` function to run in stealth mode (optional).

- **`check()` Function:**
  - Contains the main logic for detecting and recording keystrokes.
  - Handles both regular and special keys.

- **`hide()` Function:**
  - Hides the console window to run the keylogger in the background.

## Compilation

This project can be compiled using any standard C++ compiler. For example, using `g++`:

```bash
g++ keylogger.cpp -o keylogger -luser32
```

## Note on Compatibility

This keylogger is designed for Windows operating systems, as it uses Windows-specific libraries like `<Windows.h>` and `<Winuser.h>`.

## Contributing

Contributions, issues, and feature requests are welcome. Feel free to check [issues page](#) if you want to contribute.

## License

Distributed under the MIT License. See `LICENSE` for more information.

---
