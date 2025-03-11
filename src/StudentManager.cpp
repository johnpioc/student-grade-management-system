#include "../include/StudentManager.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

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

void StudentManager::readFromFile() {
    std::ifstream inputFile("data/students.txt");

    if (inputFile.good()) { // File exists and is readable
        std::string line;
        // Line Structure: ID, name, grade-1, grade-2, ... , grade-n
        while (std::getline(inputFile, line)) {
            std::string word;
            std::vector<std::string> tokens;
            std::istringstream ss(line);

            while (ss >> word) {
                tokens.push_back(word);
            }

            int id = std::stoi(tokens[0]);
            std::string name = tokens[1] + tokens[2];

            Student newStudent = Student(name, id);

            for (int i = 3; i < tokens.size(); i++) {
                newStudent.addNewGrade(std::stoi(tokens[i]));
            }
        }

        std::cout << "Data has been found from" << students.size() << "students and has been uploaded to the student manager.\n\n";
    } else {
        std::cout << "No student records were found.\n\n";
    }
}

