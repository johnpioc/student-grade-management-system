#include "Student.h"

Student::Student(std::string name, int id) {
    Student::name = name;
    Student::id = id;
}

std::string Student::getName() {
    return name;
}

int Student::getId() {
    return id;
}

double Student::getGPA() {
    double runningSum = 0;

    for (int i = 0; i < grades.size(); i++) {
        runningSum += grades[i];
    }

    return runningSum / static_cast<double>(grades.size());
}

std::vector<int> Student::getAllGrades() {
    return grades;
}

void Student::addNewGrade(int grade) {
    grades.push_back(grade);
}
