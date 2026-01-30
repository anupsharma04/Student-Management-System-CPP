#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>
#include "Student.h"

/**
 * @class StudentManager
 * @brief Handles the logic of the management system (CRUD, Sorting, File I/O).
 */
class StudentManager {
private:
    std::vector<Student> students; // Core data storage

public:
    StudentManager() { loadFromFile(); } // Automatically loads data on startup
    void Menu(); // The primary UI loop
    void add();
    void display() const;
    void searchById() const;
    void updateStudentDetails();
    void displayStats() const;
    void deleteStudent();
    void sortByGPA();
    void saveToFile() const;
    void loadFromFile();
    
    // Internal helper for UI formatting
    void printHeader() const;
    void printStudentRow(const Student& s) const;
};

#endif