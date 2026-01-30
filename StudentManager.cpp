#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "StudentManager.h"
#include "Student.h"

using namespace std;

/**
 * @brief Main UI Loop for the system.
 */
void StudentManager::Menu() {
    int choice;
    do {
        system("clear"); // Use "cls" if on Windows
        cout << "\n==========================================\n";
        cout << "        STUDENT MANAGEMENT SYSTEM         \n";
        cout << "==========================================\n";
        cout << "1. Add Student      2. Display All\n";
        cout << "3. Search by ID     4. Update Details\n";
        cout << "5. Stats            6. Delete Student\n";
        cout << "7. Sort by GPA      8. Save to File\n";
        cout << "9. Exit\n";
        cout << "Choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch(choice) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: searchById(); break;
            case 4: updateStudentDetails(); break;
            case 5: displayStats(); break;
            case 6: deleteStudent(); break;
            case 7: sortByGPA(); break;
            case 8: saveToFile(); break;
            case 9: cout << "Exiting...\n"; break;
        }
        if (choice != 9) {
            cout << "\nPress Enter to continue...";
            cin.ignore(1000, '\n');
            cin.get();
        }
    } while (choice != 9);
}

void StudentManager::add() {
    Student s;
    string name;
    int id, age, n;
    
    cout << "Enter ID: "; cin >> id;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, name);
    cout << "Enter Age: "; cin >> age;
    cout << "Number of grades: "; cin >> n;
    
    vector<double> g(n);
    for(int i=0; i<n; ++i) {
        cout << "Grade " << i+1 << ": ";
        cin >> g[i];
    }
    
    s.setID(id); s.setName(name); s.setAge(age); s.setGrades(g);
    students.push_back(s);
    cout << "Record added successfully.\n";
}

void StudentManager::display() const {
    if (students.empty()) { cout << "No records.\n"; return; }
    printHeader();
    for(const auto& s : students) printStudentRow(s);
}

void StudentManager::sortByGPA() {
    // Demonstrating Bubble Sort logic O(n^2)
    for (size_t i = 0; i < students.size() - 1; ++i) {
        for (size_t j = 0; j < students.size() - i - 1; ++j) {
            if (students[j].calculateGPA() < students[j+1].calculateGPA()) {
                swap(students[j], students[j+1]);
            }
        }
    }
    cout << "Sorted by GPA (Highest to Lowest).\n";
}

void StudentManager::searchById() const {
    int searchId;
    cout << "Enter ID to search: "; cin >> searchId;
    for (const auto& s : students) {
        if (s.getId() == searchId) {
            printHeader();
            printStudentRow(s);
            return;
        }
    }
    cout << "Student not found.\n";
}

void StudentManager::displayStats() const {
    if (students.empty()) return;
    double sum = 0, maxG = 0, minG = 4.0;
    for (const auto& s : students) {
        double gpa = s.calculateGPA();
        sum += gpa;
        if (gpa > maxG) maxG = gpa;
        if (gpa < minG) minG = gpa;
    }
    cout << "Average GPA: " << (sum / students.size()) << "\n";
    cout << "Highest GPA: " << maxG << "\n";
    cout << "Lowest GPA:  " << minG << "\n";
}

void StudentManager::deleteStudent() {
    int targetId;
    cout << "Enter ID to delete: "; cin >> targetId;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == targetId) {
            students.erase(it);
            cout << "Record deleted.\n";
            return;
        }
    }
    cout << "ID not found.\n";
}

void StudentManager::updateStudentDetails() {
    int targetId;
    cout << "Enter ID to update: "; cin >> targetId;
    for (auto& s : students) {
        if (s.getId() == targetId) {
            string newName;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newName);
            s.setName(newName);
            cout << "Update successful.\n";
            return;
        }
    }
    cout << "ID not found.\n";
}

void StudentManager::saveToFile() const {
    ofstream file("students.txt");
    if (!file) { cout << "Error opening file.\n"; return; }
    
    for (const auto& s : students) {
        file << s.getId() << "," << s.getName() << "," << s.calculateGPA() << "\n";
    }
    file.close();
    cout << "Data exported to students.txt\n";
}

void StudentManager::loadFromFile() {
    ifstream file("students.txt");
    if (!file) return; // If no file exists yet, just start with an empty list

    string line;
    // We clear the current vector to avoid duplicates if called multiple times
    students.clear();

    while (getline(file, line)) {
        // Here you would implement logic to parse the saved strings back into 
        // Student objects and push_back() them into the 'students' vector.
    }
    file.close();
}

// UI Helpers
void StudentManager::printHeader() const {
    cout << left << setw(10) << "ID" << setw(20) << "Name" << "GPA" << endl;
    cout << string(35, '-') << endl;
}

void StudentManager::printStudentRow(const Student& s) const {
    cout << left << setw(10) << s.getId() << setw(20) << s.getName() << fixed << setprecision(2) << s.calculateGPA() << endl;
}