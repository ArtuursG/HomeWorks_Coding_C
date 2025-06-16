# 📘 Second Homework – Matrix and Shape Detection Tasks in C++

This folder contains two C++ programs focusing on matrix manipulation and shape recognition using flood-fill algorithms. These exercises are designed to enhance understanding of 2D arrays, rotation, recursion, and breadth-first search (BFS) techniques.

---

## 🧾 2_1_HW.cpp – Matrix Rotation (NxN)
This program:

- Prompts the user to enter `N = 2` or `3`.
- Fills an `N x N` matrix with **random numbers between 10 and 99**.
- Displays the **original matrix**.
- Rotates the matrix **90° clockwise** and prints the rotated result.

### 💡 Concepts practiced:
- Dynamic matrix generation
- Nested loops
- Rotation logic via `matrix90[j][N - 1 - i] = matrix[i][j]`
- Use of `srand()` and `rand()` for random number generation

---

## 🧩 2_2_HW.cpp – Shape Detection in a Grid
This program:

- Analyzes a **2D grid** of 0s (empty) and 1s (filled).
- Detects **connected shapes** (figures) where cells are connected via shared edges.
- Uses **Breadth-First Search (BFS)** via a recursive flood-fill approach to:
  - Identify each shape
  - Calculate its area (number of cells)
- Outputs the **area of the largest shape**.

### 🧠 Features:
- Grid analysis using `std::vector<std::vector<int>>`
- Tracking visited cells with `std::vector<std::vector<bool>>`
- Recursive component discovery using `queue` for BFS
- Axis navigation arrays `dx[]` and `dy[]` to scan neighbors

---

## 🛠️ Skills Applied
- Matrix creation and traversal
- Conditional checks and bounds validation
- Recursive logic and component detection
- Use of the C++ Standard Library (`<vector>`, `<queue>`, `<algorithm>`)

---

> 🧑‍💻 Author: Artūrs G. | Year: 2024
