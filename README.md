# Student Management System (C++) 🎓

A professional-grade command-line interface (CLI) tool for managing student records. This project demonstrates advanced C++ concepts, including **Object-Oriented Programming (OOP)**, **File Persistence**, and **Algorithm Design**.

## 🚀 Key Features
* **Full CRUD Lifecycle:** Create, Read, Update, and Delete student records with ease.
* **Data Persistence:** Records are exported to and loaded from `students.txt` using C++ File Streams (`fstream`).
* **Modular Architecture:** Utilizes a clean separation of concerns with Header (`.h`) and Implementation (`.cpp`) files.
* **Sorting Logic:** Custom implementation of the Bubble Sort algorithm to organize students by academic performance.
* **Input Validation:** Robust error handling to prevent crashes from invalid data types (e.g., character input for numeric fields).

## 🛠️ Technical Toolkit
* **Language:** C++
* **Paradigm:** Object-Oriented Programming
* **Core Libraries:** `<vector>`, `<fstream>`, `<iomanip>`, `<algorithm>`

## 📁 Project Structure
* `Student.h/cpp`: The Data Model (Encapsulated student attributes).
* `StudentManager.h/cpp`: The Controller (Logic, File I/O, and UI Menu).
* `main.cpp`: The Application Entry Point.

## 💻 How to Run
Ensure you have a C++ compiler (like `g++`) installed:

1. Clone the repository:
   ```bash
   git clone [https://github.com/anupsharma04/Student-Management-System-CPP.git](https://github.com/anupsharma04/Student-Management-System-CPP.git)
2. Compile:
   ```bash
   g++ main.cpp Student.cpp StudentManager.cpp -o StudentSystem
3. Run:
   ```bash
   ./StudentSystem

💬 Feedback & Contributions
I am a Computer Science student currently refining my software engineering skills. If you find a bug, have an idea for a more efficient logic flow, or see a way to improve the security of this simulation, I would love to hear from you!

Please feel free to:

Open an Issue if you spot a bug.
Submit a Pull Request with your suggested improvements.
Reach out directly on LinkedIn(https://www.linkedin.com/in/anup-sharma04/) for a technical chat!
Created by Anup Sharma - Aspiring Software Engineer
