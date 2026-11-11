# Student Performance Analyzer

A console-based C++ application designed to manage student academic records, calculate performance statistics, and identify students based on their academic results.

---

## 🎯 Project Objective

To develop a simple student management system using fundamental C++ programming concepts while providing an organized way to calculate and analyze student academic performance.

---

## ✨ Features

- **Add Student Details:** Enter roll number, name, and marks across five subjects.
- **Input Validation:** Ensures entered marks are within the range of 0 to 100 (inclusive).
- **Calculate Total & Average:** Automatically calculates total score and average marks for every student.
- **Grade Calculation:** Assigns letter grades based on student average.
- **Display Records:** Neatly presents the academic records of all students.
- **Search Functionality:** Find any student by roll number or name.
- **Find Class Topper:** Identifies and displays the student with the highest total marks.
- **Class Average:** Calculates overall class performance statistics.
- **Above-Average Students:** Filters and lists students performing above the class average.

---

## 🛠️ Concepts & Technologies Used

- **Language:** C++
- **Concepts Implemented:**
  - Structures (`struct`)
  - Arrays
  - Pointers
  - Modular Functions
  - Recursion
  - Conditional Statements and Loops

---

## 📊 Grading System

| Average Marks | Grade |
| :--- | :---: |
| 90 and above | **A** |
| 75 – 89 | **B** |
| 60 – 74 | **C** |
| 50 – 59 | **D** |
| Below 50 | **F** |

---

## 🚀 How to Run

### Method 1: Using an IDE (Code::Blocks, CLion, VS Code)

1. Clone or download this repository.
2. Open the `.cpp` file or project in your preferred IDE.
3. Build and run the project (Press `F9` in Code::Blocks).
4. Follow the interactive menu displayed in the console.

### Method 2: Using the Command Line (g++)

1. Open a terminal inside the project directory.
2. Compile the source file:

   ```bash
   g++ main.cpp -o analyzer
   ```

3. Run the executable:

   **Windows:**
   ```bash
   analyzer.exe
   ```

   **Linux / macOS:**
   ```bash
   ./analyzer
   ```
