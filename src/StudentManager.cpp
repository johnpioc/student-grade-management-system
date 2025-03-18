#include "../include/StudentManager.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

void StudentManager::addStudent(Student newStudent) {
    students.push_back(newStudent);
    saveToFile();
}

std::vector<Student> StudentManager::getAllStudents() {
    return students;
}

Student StudentManager::removeStudentByIndex(int index) {
    Student studentToRemove = students[index];
    students.erase(students.begin() + index);
    return studentToRemove;
}

int StudentManager::getNumOfStudents() {
    return students.size();
}

Student* StudentManager::getStudentById(int id) {
    for (Student& student : students) {
        if (student.getId() == id) {
            return &student;
        }
    }

    return nullptr;
}

void StudentManager::displayStudents() {
    if (getNumOfStudents() == 0) {
        std::cout << "No students on file.\n\n";
    } else { // Create table of students
        // Header
        std::cout << std::left
            << std::setw(10) << "ID"
            << std::setw(20) << "Name"
            << std::setw(10) << "GPA"
            << "\n";

        std::cout << std::string(40, '-') << "\n";

        for (Student student : getAllStudents()) {
            std::cout << std::left
                << std::setw(10) << student.getId()
                << std::setw(20) << student.getName()
                << std::setw(10) << student.getGPA()
                << "\n";
        }
    }
    std::cout << "\n";
}

void StudentManager::addStudentWorkflow() {
    std::string idString;
    std::cout << "ID of new student: ";
    std::getline(std::cin, idString);
    int id = std::stoi(idString);

    std::string name;
    std::cout << "Name of the student: ";
    std::getline(std::cin, name);

    Student newStudent = Student(name, id);

    std::string gradesString;
    std::cout << "Grades of student (separated by spaces): ";
    std::getline(std::cin, gradesString);
    std::cout << "\n";

    std::istringstream ss(gradesString);
    int num;

    while (ss >> num) {
        newStudent.addNewGrade(num);
    }

    addStudent(newStudent);
}

void StudentManager::saveToFile() {
    std::ofstream outputFile("../data/students.txt");

    for (Student student : students) {
        std::string lineString = std::to_string(student.getId()) + " " + student.getName() + " ";
        for (int grade : student.getAllGrades()) {
            lineString += std::to_string(grade) + " ";
        }
        lineString += "\n";

        outputFile << lineString;
    }

    outputFile.close();
}


void StudentManager::readFromFile() {
    std::ifstream inputFile("../data/students.txt");

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
            std::string name = tokens[1] + " " + tokens[2];

            Student newStudent = Student(name, id);

            for (int i = 3; i < tokens.size(); i++) {
                newStudent.addNewGrade(std::stoi(tokens[i]));
            }

            addStudent(newStudent);
        }

        inputFile.close();
        std::cout << "Data has been found from " << students.size() << " students and has been uploaded to the student manager.\n\n";
    } else {
        std::cout << "No student records were found.\n\n";
    }
}



