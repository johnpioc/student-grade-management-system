#include "../include/StudentManager.h"

void StudentManager::addStudent(Student newStudent) {
    students.push_back(newStudent);
}

std::vector<Student> StudentManager::getAllStudents() {
    return students;
}

Student StudentManager::removeStudentByIndex(int index) {
    Student studentToRemove = students[index];
    students.erase(students.begin() + index);
    return studentToRemove;
}
