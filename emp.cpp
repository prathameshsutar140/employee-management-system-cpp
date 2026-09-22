#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <stdio.h>

// Base Class: Person
class Person {
protected:
    int emp_id;
    char emp_name[50];
public:
    void getPersonDetails() {
        cout << "Enter Employee ID: ";
        cin >> emp_id;
        cout << "Enter Employee Name: ";
        // Using cin.ignore() or fflush if needed, but gets/cin.getline works safely here
        cin >> emp_name; 
    }
};

// Derived Class: Employee (Demonstrating Inheritance)
class Employee : public Person {
private:
    double basic_salary;
    int leaves_taken;
    double net_salary;
public:
    void getSalaryDetails() {
        getPersonDetails(); // Call base class function
        cout << "Enter Basic Salary (Rs.): ";
        cin >> basic_salary;
        cout << "Enter Leaves Taken in the Month: ";
        cin >> leaves_taken;
        calculateNetSalary();
    }

    void calculateNetSalary() {
        double deduction = 0;
        if (leaves_taken > 2) {
            deduction = (leaves_taken - 2) * 500.0;
        }
        net_salary = basic_salary - deduction;
    }

    void displayEmployee() {
        cout << "\n-----------------------------------";
        cout << "\nEmployee ID   : " << emp_id;
        cout << "\nName          : " << emp_name;
        cout << "\nBasic Salary  : Rs. " << basic_salary;
        cout << "\nLeaves Taken  : " << leaves_taken;
        cout << "\nNet Salary    : Rs. " << net_salary;
        cout << "\n-----------------------------------" << endl;
    }

    // Function to write data to file
    void saveToFile() {
        ofstream outFile("emp_rec.txt", ios::app);
        if (outFile) {
            outFile << emp_id << " | " << emp_name << " | Basic: " << basic_salary 
                    << " | Leaves: " << leaves_taken << " | Net: " << net_salary << "\n";
            outFile.close();
            cout << "\n[Success] Record successfully written to 'emp_rec.txt'!";
        } else {
            cout << "\n[Error] Unable to open file to save record.";
        }
    }
};

int main() {
    int choice;
    Employee emp[5]; // Array of objects (max 5 records)
    int record_count = 0;

    clrscr(); // Clear screen for Turbo C++

    cout << "=== MSBTE OOP C++ Micro-project: Employee System ===" << endl;
    
    while (1) {
        cout << "\n1. Add Employee Record\n2. View Current Session Records\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            if (record_count < 5) {
                emp[record_count].getSalaryDetails();
                emp[record_count].saveToFile();
                record_count++;
            } else {
                cout << "\n[Limit Reached] MSBTE guidelines restrict entries to a max of 5 records!\n";
            }
        } 
        else if (choice == 2) {
            if (record_count == 0) {
                cout << "\nNo records created in this session yet.\n";
            } else {
                for (int i = 0; i < record_count; i++) {
                    emp[i].displayEmployee();
                }
            }
        } 
        else if (choice == 3) {
            cout << "\nExiting project execution. Thank you!\n";
            break;
        } 
        else {
            cout << "\nInvalid choice! Please try again.\n";
        }
    }
    
    getch(); // Hold screen before exit in Turbo C++
    return 0;
}