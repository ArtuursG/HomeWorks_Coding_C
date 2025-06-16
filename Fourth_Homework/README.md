# 🗡️ Fourth Homework — C++ RPG Combat Simulation

This project is a basic simulation of an RPG-style combat system written in C++. 
It uses object-oriented programming principles to model characters, swords, and shields. 
The program simulates movement and fighting between two characters.

---

## 📁 File Structure

| File              | Description                                                                  |
|-------------------|------------------------------------------------------------------------------|
| `main.cpp`        | Main function: creates characters, moves them, and simulates the battle     |
| `Character.h/cpp` | Defines the `Character` class with health, movement, attack, and defense     |
| `Sword.h/cpp`     | Defines the `Sword` class including weight, quality, and damage calculations |
| `Shield.h/cpp`    | Defines the `Shield` class including size, protection, and block logic       |

---

## 💡 Key Concepts

### ✔️ Object-Oriented Design

- **Encapsulation**: Each component (character, sword, shield) is implemented as a separate class
- **Constructors**: Ensure values like weight and protection stay within valid limits
- **Destructor**: Prints a message (`Game over for <name>`) when a character is destroyed

### 🥊 Combat Mechanics

- `Fight()` function calculates attack vs. defense and applies damage
- Combat loop runs until one character's life reaches 0

### 👣 Movement Tracking

- Characters remember the last 10 directions using a `char[10]` array
- Valid directions: `w` (up), `s` (down), `a` (left), `d` (right)

### ⚔️ Weapon & Shield Logic

- **Sword**: Damage = `weight * quality`, quality decreases after each use
- **Shield**: Block = `size * protection`, size decreases after blocking
- Both can be sharpened/repaired (although not used in `main.cpp`)


## 🧪 Sample Output
```
Arthur vs Goblin

Goblin is dead and cannot take actions.
Name: Arthur
Status: Alive (34 HP)
Path: sdaw------
Sword - Weight: 5, Quality: 3
Shield - Size: 2, Protection: 4

Name: Goblin
Status: Dead
Path: ssssssssss
Sword - Weight: 3, Quality: 2
Shield - Size: 1, Protection: 2

Game over for Goblin
Game over for Arthur
```


## ▶️ How to Compile & Run

```
g++ main.cpp Character.cpp Sword.cpp Shield.cpp -o game
./game
```


## 📌 Notes
- No external libraries required — uses only standard C++.
- Meant for educational purposes: OOP design, encapsulation, and logic simulation.
- Can be extended with features like leveling up, healing, inventory, or more characters.

---
