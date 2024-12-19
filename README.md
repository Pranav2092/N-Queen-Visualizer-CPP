# N-Queens Problem Visualizer

This repository contains a **C++ implementation** of the N-Queens problem with a visualizer. The program not only solves the problem but also visually demonstrates the process of placing queens on the board using the backtracking algorithm.

## Table of Contents
- [About](#about)
- [Features](#features)
- [How It Works](#how-it-works)
- [Code Structure](#code-structure)
  - [Main Functions](#main-functions)
- [How to Run](#how-to-run)
- [Tools and Technologies Used](#tools-and-technologies-used)

---

## About

The **N-Queens problem** is a classic combinatorial problem where the task is to place `N` queens on an `N x N` chessboard such that no two queens threaten each other. This means:
1. No two queens can be in the same row.
2. No two queens can be in the same column.
3. No two queens can be on the same diagonal.

This program demonstrates the process of solving the N-Queens problem visually using terminal output.

---

## Features

- **Visualization:** Displays the board state as the backtracking algorithm progresses.
- **Interactivity:** Option to view subsequent solutions during the execution.
- **Customizable Input:** Users can input any board size `N`.
- **Multi-Solution Support:** Finds all possible solutions for the given `N`.

---

## How It Works

### Algorithm
The program employs a **backtracking algorithm**:
1. Start placing queens row by row.
2. At each row, check all columns for safe positions.
3. If a position is safe:
   - Place the queen.
   - Mark the columns and diagonals threatened by this queen.
4. Recursively solve for the next row.
5. If no valid position exists, backtrack and remove the last placed queen.

### Visualization
The board is printed on the terminal, showing:
- `⇯` ("\u21EF") for a queen.
- `▣` ("\u25A3") for threatened squares during solving.
- `▢` ("\u25A2") for empty squares.

The board updates dynamically, pausing at each step to show progress.

---

## Code Structure

### Main Functions

#### `display()`
- **Purpose:** Prints the current state of the board to the terminal.
- **Input:** None (uses class variables `board` and `state`).
- **Logic:**
  - Iterates through the `board` matrix.
  - Differentiates between solving and solved states to format the display.

#### `isSafe(int row, int col)`
- **Purpose:** Determines if a queen can be placed at `(row, col)`.
- **Input:** Row and column indices.
- **Logic:** Checks if the cell is unthreatened.

#### `solve(int row)`
- **Purpose:** Implements the recursive backtracking algorithm to place queens.
- **Input:** Current row index.
- **Logic:**
  - Attempts to place a queen in every column of the current row.
  - Marks threatened positions on the board.
  - Recursively solves for the next row.
  - Backtracks if no valid positions remain.

#### `countSolutions(int row)`
- **Purpose:** Recursively counts all possible solutions.
- **Input:** Current row index.
- **Logic:** Similar to `solve`, but without visualization. Simply increments a counter for each valid solution.

#### `solveNQueens(int n)`
- **Purpose:** Initializes the board and orchestrates the solving process.
- **Input:** Size of the board (`n`).
- **Logic:**
  - Resets all class variables.
  - Calls `countSolutions` to determine the total number of solutions.
  - Calls `solve` to find and display solutions interactively.

#### `main()`
- **Purpose:** Entry point of the program.
- **Input:** Reads `n` from the user.
- **Logic:** Instantiates the `NQueensVisualizer` class and calls `solveNQueens`.

---

## How to Run

### Compilation
Ensure you have a C++ compiler installed. Use the following commands to compile and run the program:

```bash
# Compile the program
$ g++ -o nqv NQueensVisualizer.cpp

# Run the program
$ ./nqv
```

### Execution
1. Enter the desired board size (`N`).
2. The program will display the board as it solves the problem.
3. If there are multiple solutions, you can choose to view the next solution by pressing `1`, or stop by pressing `0`.

---

## Tools and Technologies Used

### Programming Language
- **C++:** The entire program is implemented in C++ for its efficiency and flexibility.

### Libraries
- **Standard Template Library (STL):** Utilized for dynamic arrays (`vector`) and input/output operations.
- **`unistd.h`:** Used to add delays for visualization (`sleep`).

### Terminal Features
- **ANSI Escape Codes:** Used to clear the terminal and update the display dynamically.
- **Unicode Characters:** Enhance board visualization.

---

## Author 👨‍💻
Pranav Sharma

Passionate about problem-solving and creating engaging visualizations in C++.

---

Feel free to contribute, report bugs, or suggest enhancements! 😊

