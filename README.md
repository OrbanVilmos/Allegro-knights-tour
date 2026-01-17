# Knight's Tour Visualizer

A C++ application that solves and visualizes the classic **Knight's Tour** problem on an 8x8 chessboard using the **Allegro 4.0** graphics library.

## Project Overview
The Knight's Tour is a mathematical puzzle where the objective is to find a sequence of moves for a knight on a chessboard such that the knight visits every square exactly once. 

This program starts the knight from the top-left corner of the board and utilizes a **backtracking algorithm** to find the first valid solution. Once found, the program animates the knight's journey across the board in real-time.

## Preview
<p align="center">
  <img src="image.png" alt="Knight's Tour Visualization" width="600">
</p>

## Key Features
* **Backtracking Implementation:** Explores potential moves to find a complete path (not optimal for running time, used it to show how inefficient backtracking can be).
* **Graphical Visualization:** Uses Allegro 4.0 to render the chessboard, the knight (red circle), and the visited squares (blue blocks).
* **Step-by-step Animation:** Shows the knight's progression with a delay to make the pathfinding process observable.
* **Coordinate Logging:** Prints the (x, y) coordinates of each step to the console.

## Built With
* **C++** - Core logic and algorithm.
* **Allegro 4.0** - Legacy graphics library used for rendering and window management.
* **Custom Graphics Wrapper:** Uses `cGrafika` and `cVektor` libraries for simplified drawing operations. (The libraries were written by me to simplify Allegro coding).

## How It Works
1.  **Initialization:** The board is cleared, and the knight is placed at the starting position (top-left).
2.  **Pathfinding:** The `back()` function recursively attempts all 8 possible L-shaped moves for a knight.
3.  **Validation:** The `jo()` function checks if a move is within board boundaries and if the square has already been visited.
4.  **Visual Output:** Once a full solution of 64 moves is found, the `kiir()` function triggers the animation on the graphical interface.

## Getting Started
To run this project locally, you will need:
* A C++ compiler (like MinGW).
* The Allegro 4.0 library installed and linked in your IDE.