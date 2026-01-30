#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

/**
 * @class Student
 * @brief Represents a single student entity and their academic data.
 */
class Student {
private:
    std::string name;
    int id;
    int age;
    std::vector<double> grades;

public:
    // Constructor to ensure clean initialization
    Student() : name(""), id(0), age(0) {}

    // Getters and Setters (Encapsulation)
    void setName(std::string stdName);
    void setID(int stdID);
    void setAge(int stdAge);
    void setGrades(const std::vector<double>& stdGrades);

    std::string getName() const;
    int getId() const;
    int getAge() const;
    std::vector<double> getGrades() const;

    /**
     * @brief Calculates GPA based on the average of grades.
     * Maps 0-100 score to a 4.0 scale.
     */
    double calculateGPA() const;
};

#endif