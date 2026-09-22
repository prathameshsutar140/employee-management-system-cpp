# 💼 Employee Management System in C++

An **Object-Oriented C++** console application designed for employee details management, payroll calculation with leave deductions, and persistent storage via file handling.

---

## ✨ Features

- 🏗️ **Inheritance Structure**: Implements a base `Person` class and a derived `Employee` class.
- 💵 **Automated Net Salary Calculation**: Calculates deductions based on monthly leave limits (deducts Rs. 500 per excess leave beyond 2 allowed leaves).
- 📁 **File Handling**: Automatically appends employee records to `emp_rec.txt` for persistent storage.
- 🖥️ **Session Record Display**: Features formatted console output to display all records added during the active session.
  

---
##🚀 How to Run

Clone or download the repository:

git clone <repository-url>

Compile emp.cpp using a C++ compiler (such as GCC or Turbo C++):
g++ emp.cpp -o emp_system
Run the compiled executable:
./emp_system

🛠️ Language & Tools

💻 Language: C++

🧠 Concepts: Object-Oriented Programming (OOP), Single Inheritance, File I/O (fstream)
---




## 📊 Output Sample

```text
-----------------------------------
Employee ID   : 101
Name          : Alex
Basic Salary  : Rs. 35000
Leaves Taken  : 4
Net Salary    : Rs. 34000
-----------------------------------
---
