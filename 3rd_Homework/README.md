# 🧠 Third Homework – Time Format Checker & Word Guessing Game in C++

This folder contains two projects that explore:

1. Validating user input using string parsing and formatting.
2. Implementing an interactive word guessing game with scoring logic and hidden word reveal.

---

## ⏰ 3_1_HW.cpp – Time Format Validator

### ✅ Goal
Check if a time string is valid and follows the correct format `hh:mm:ss`.

### 📋 What it does
- Accepts a string input (e.g. `23:09:03`)
- Verifies:
  - Correct structure (2 colons, exactly two digits per section)
  - Only numeric characters
  - Valid hour (0–23), minute (0–59), and second (0–59) ranges

### 🔍 Example outputs
| Input        | Output                     |
|--------------|----------------------------|
| 23:09:03     | ✅ Correct time and format |
| 2:2:2        | ❌ Incorrect format        |
| 12:02:94     | ❌ Invalid time            |
| 14.05.35     | ❌ Incorrect format        |
| qw2:we34     | ❌ Incorrect format        |

---

## 🎮 3_2_HW.* – Word Guessing Game

### 🕹️ Files
- `MAIN_3_2_HW.cpp`: Game logic and main loop
- `HEADER_3_2_HW.cpp`: Helper functions for gameplay
- `HEADER_3_2_HW.hpp`: Function declarations (header file)

### 🎯 Objective
Create an interactive word guessing game with the following rules:

### 🔧 Features
- Randomly chooses one of 20 fruit names (in Latvian)
- Displays hidden word using dots (`.`) representing letters
- User guesses letters:
  - Correct guesses reveal letters
  - Incorrect guesses add a penalty point
- Player has up to **10 penalty points**
- User can quit early by entering `'0'`
- For each correctly guessed word:
  - 5 penalty points are subtracted
  - The next random word is offered (words don’t repeat)
- At the end, the program displays the number of guessed words

### 📌 Example Words
```
"ābols", "banāns", "ķirsis", "vīnoga", "apelsīns", ...
```

---

### 🛠️ Key Concepts Used
- `std::vector`, `std::string`, and `char` processing
- Function design using headers (`.hpp`)
- Random selection (`rand()`, `srand(time(0))`)
- Game loop and state management

---

## 👨‍💻 Author
Artūrs G. – 2024
