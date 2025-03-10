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

int Student::getGPA() {
    int runningSum = 0;

    for (int i = 0; i < grades.size(); i++) {
        runningSum += grades[i];
    }

    return runningSum / grades.size();
}

std::vector<int> Student::getAllGrades() {
    return grades;
}

void Student::updateName(std::string newName) {
    name = newName;
}

void Student::addNewGrade(int grade) {
    grades.push_back(grade);
}

int Student::removeGradeByIndex(int index) {
    int toRemove = grades[index];
    grades.erase(grades.begin() + index);
    return toRemove;
}

