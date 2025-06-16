# Homework 6 – Operator Overloading, Polymorphism & Templates in C++

This project demonstrates advanced object-oriented programming concepts in C++ including class inheritance, virtual functions, operator overloading, and template-based queues. It extends the earlier character-based combat simulation to include:

## ✅ Key Features

### 1. **Class Hierarchy**
- `Character` (base class)
- `Hero`, `Monster`, `Boss` (derived classes)
  - Each class overrides the `Print()` method
  - `Boss` can "Eat" a `Hero`, gaining health and increasing its `heads` count
  - `Hero` can "Kill" a `Monster`, gaining experience

### 2. **Operator Overloading**
Implemented in the `Character` class:
- Assignment operator `=`
- Comparison operators: `==`, `!=`, `<`, `>`, `<=`, `>=` (based on `life + strength`)
- Increment/Decrement:
  - `++` (prefix and postfix): increases life
  - `--` (prefix and postfix): decreases life
- Stream operators `>>` and `<<` for input/output

### 3. **Template Queue**
- Generic `Queue<T>` template class for storing any type (used with `Character`)
- Implements:
  - `enqueue()`, `dequeue()`
  - `Sort()` using overloaded `<` operator
  - `PrintQueue()` for displaying queue contents

### 4. **Demonstration**
- `main3.cpp` shows:
  - Creating and manipulating a `Queue<Character>`
  - Sorting and dequeuing with output at each step

## 📁 File Structure
```
Character.h / .cpp
Hero.h / .cpp
Monster.h / .cpp
Boss.h / .cpp
Sword.h / .cpp
Shield.h / .cpp
Queue.h
main3.cpp
```

## 🛠️ Concepts Practiced

- Polymorphism and inheritance
- Operator overloading for intuitive object manipulation
- Templates and generic programming
- Composition and encapsulation
- Clean memory-safe queue implementation

## 🧪 Usage

Compile with g++:
```
g++ main3.cpp Character.cpp Hero.cpp Monster.cpp Boss.cpp Shield.cpp Sword.cpp -o game
./game
```


