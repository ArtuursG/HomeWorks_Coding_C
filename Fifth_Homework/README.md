# 🧠 Fifth Homework – Advanced C++ Inheritance and Polymorphism

This C++ project demonstrates **object-oriented programming** using **multi-level inheritance** and **polymorphism**. It introduces classes like `Character`, `Hero`, `Monster`, and `Boss`, and models a mini RPG battle system with virtual functions and pointer arrays of derived types.

---

## 🗂️ File Structure

| File         | Purpose                                                  |
|--------------|----------------------------------------------------------|
| `main2.cpp`  | Entry point. Simulates fights between Hero, Monster, Boss|
| `Character.*`| Base class with stats, movement tracking, and Print()    |
| `Hero.*`     | Inherits `Character`, adds experience and Kill() method  |
| `Monster.*`  | Inherits `Character`, adds level                         |
| `Boss.*`     | Inherits `Monster`, adds multiple heads and Eat() method |
| `Sword.*`    | Weapon with weight and quality. Handles damage logic     |
| `Shield.*`   | Defense with size and protection. Handles block logic    |

---

## 🧱 Class Hierarchy
```
Character
├── Hero (adds experience, Kill())
├── Monster (adds level)
└── Boss (adds heads, Eat())
```

## ⚔️ Key Features

- **Inheritance**:
  - `Hero` and `Monster` derive from `Character`
  - `Boss` extends `Monster`
- **Polymorphism**:
  - Virtual `Print()` method is overridden in each subclass
  - Array of `Character*` stores and processes all object types

- **Combat Logic**:
  - `Hero::Kill(Monster&)`: kills monster and gains experience
  - `Boss::Eat(Hero&)`: consumes a hero to gain health and one head

- **Random Events**:
  - 5 random movement directions (`w`, `s`, `a`, `d`)
  - 5–10 random damage applied to each character across 5 iterations


## 🧪 Sample Flow

1. Objects `Hero`, `Monster`, and `Boss` are created and printed
2. `Hero` kills `Monster`, `Boss` eats `Hero`
3. 9 objects (3 from each class) are created and stored in a `Character*` array
4. Each object moves and receives random damage over 5 steps
5. All object states are printed after the simulation


## ▶️ Compile & Run

```
g++ main2.cpp Character.cpp Hero.cpp Monster.cpp Boss.cpp Sword.cpp Shield.cpp -o simulation
./simulation
```


## 📌 Notes
- Uses virtual destructors and function overriding
- Demonstrates multi-level inheritance
- Easy to expand with additional abilities (healing, attack types, etc.)
- Designed for educational use to explore OOP in C++


## 🧠 Educational Value
- Inheritance
- Polymorphism (virtual functions)
- Constructors and member initializer lists
- Dynamic memory and arrays of base class pointers
- Clear encapsulation of weapon and armor logic

---