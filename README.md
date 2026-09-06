# Math Game in C++ 🧮

## Overview
A console-based Mathematical Quiz Game developed in C++. This project demonstrates advanced procedural programming concepts, focusing on memory management, clean code architecture, and logical problem-solving.

## Key Features
* **Dynamic Gameplay:** Users can choose from 4 difficulty levels (Easy, Med, Hard, Mix) and 5 operation types (Addition, Subtraction, Multiplication, Division, Mix).
* **State Management:** Utilizes a central `struct` passed by reference (`&`) to efficiently track game rounds, scores, and settings across multiple functions without memory waste.
* **Recursive Logic:** Implements a recursive function approach to handle randomized mixed operations smoothly.
* **Data Mapping:** Uses `enum` and array mapping to convert raw numerical choices into readable UI text (e.g., converting Level '2' to 'Medium').

## Technical Skills Demonstrated
* Pass by Reference vs. Pass by Value.
* Enums & Structs integration.
* Recursion (Self-calling functions).
* Switch-Case logic & Flow Control.
* Random Number Generation with time seeding.

## How to Play
1. Compile and run the `.cpp` file.
2. Select the number of questions.
3. Choose your preferred difficulty level and mathematical operation.
4. Answer the generated questions. The system will immediately validate your answer.
5. Review your final performance report at the end of the game!

---
*Developed by Moaaz Hejazi.*
