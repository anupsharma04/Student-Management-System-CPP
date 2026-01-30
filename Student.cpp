#include "Student.h"

void Student::setName(std::string stdName) { name = stdName; }
void Student::setID(int stdID) { id = stdID; }
void Student::setAge(int stdAge) { age = stdAge; }
void Student::setGrades(const std::vector<double>& stdGrades) { grades = stdGrades; }

std::string Student::getName() const { return name; }
int Student::getId() const { return id; }
int Student::getAge() const { return age; }
std::vector<double> Student::getGrades() const { return grades; }

double Student::calculateGPA() const {
    if (grades.empty()) return 0.0;

    double sum = 0.0;
    for (double g : grades) sum += g;
    double average = sum / grades.size();

    // Standard 4.0 GPA conversion logic
    if (average >= 90) return 4.0;
    else if (average >= 80) return 3.0;
    else if (average >= 70) return 2.0;
    else if (average >= 60) return 1.0;
    else return 0.0;
}