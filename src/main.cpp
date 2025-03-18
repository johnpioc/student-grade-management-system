#include <iostream>
#include "StudentManager.h"
#include "Utilities.h"

int getUserInput() {
    std::cout << "Choose from one of the following options (1-4):\n";
    std::cout << "1. Manage Students - add, update or remove\n";
    std::cout << "2. Display Students - view by name or GPA\n";
    std::cout << "3. Generate Report - overall gpa & gpa per student\n";
    std::cout << "4. quit the application\n\n";

    std::string inputString;
    std::cout << "Enter option: ";
    std::getline(std::cin, inputString);
    int input = std::stoi(inputString);

    switch (input) {
        case 1:
        case 2:
        case 3:
        case 4:
            return input;
        default:
            std::cout << "Not a valid option. Please try again\n";
            return getUserInput();
    }
}

void manageStudents(StudentManager studentManager) {
    std::cout << "***** MANAGE STUDENTS *****\n\n";

    while (true) {
        studentManager.displayStudents(studentManager.getAllStudents());

        std::cout << "Commands: add student [A], add grade to student [G <ID> <GRADE>], delete [D <ID>], quit [Q]\n";
        std::cout << "Type your command: ";
        std::string inputString;
        std::getline(std::cin, inputString);

        std::vector<std::string> components = splitString(inputString, ' ');

        if (components[0] == "A") {
            studentManager.addStudentWorkflow();
        } else if (components[0] == "G") {
            int idToSearch = std::stoi(components[1]);
            Student* student = studentManager.getStudentById(idToSearch);
            if (student) {
                int newGrade = std::stoi(components[2]);
                student->addNewGrade(newGrade);
                studentManager.saveToFile();
                std::cout << "Grade added successfully to student #" << idToSearch << "\n";
            } else {
                std::cout << "There is no student with the ID of " << idToSearch << ", try again.\n";
            }
        } else if (components[0] == "D") {
            int idToSearch = std::stoi(components[1]);
            studentManager.removeStudentById(idToSearch);
            studentManager.saveToFile();
        } else if (components[0] == "Q") {
            break;
        } else {
            std::cout << "\nInvalid input, try again.\n";
        }
    }
}

void viewStudents(StudentManager studentManager) {
    while (true) {
        std::cout << "***** STUDENT VIEWER *****\n\n";

        std::cout << "Choose from one of the viewing options (1-4):\n";
        std::cout << "1. Order by name (A-Z)\n";
        std::cout << "2. Order by name (Z-A)\n";
        std::cout << "3. Order by GPA (Decreasing)\n";
        std::cout << "4. Order by GPA (Increasing)\n";
        std::cout << "5. return back to main menu\n\n";

        std::cout << "Enter option: ";
        std::string inputString;
        std::getline(std::cin, inputString);
        int input = std::stoi(inputString);

        std::vector<Student> students = studentManager.getAllStudents();
        bool breakWhileLoop = false;

        switch (input) {
            case 1:
                std::sort(students.begin(), students.end(), [](Student a, Student b) {
                   return a.getName() < b.getName();
                });
                studentManager.displayStudents(students);
                break;
            case 2:
                std::sort(students.begin(), students.end(), [](Student a, Student b) {
                   return a.getName() > b.getName();
                });
                studentManager.displayStudents(students);
                break;
            case 3:
                std::sort(students.begin(), students.end(), [](Student a, Student b) {
                   return a.getGPA() > b.getGPA();
                });
                studentManager.displayStudents(students);
                break;
            case 4:
                std::sort(students.begin(), students.end(), [](Student a, Student b) {
                   return a.getGPA() < b.getGPA();
                });
                studentManager.displayStudents(students);
                break;
            case 5:
                breakWhileLoop = true;
                break;
        }

        if (breakWhileLoop) break;
    }

}

void processInput(int input, StudentManager studentManager) {
    switch (input) {
        case 1:
            manageStudents(studentManager);
            break;
        case 2:
            viewStudents(studentManager);
            break;
        case 3:
            studentManager.createReport();
    }
}

StudentManager initialiseStudentManager() {
    StudentManager studentManager = StudentManager();
    studentManager.readFromFile();
    return studentManager;
}

int main() {
    std::cout << "***** STUDENT GRADE MANAGEMENT SYSTEM *****\n\n";
    StudentManager studentManager = initialiseStudentManager();

    while (true) {
        int input = getUserInput();
        if (input == 4) break;
        processInput(input, studentManager);
    }

    std::cout << "Thank you for using the student grade management system.\n";


    return 0;
}