#include <iostream>
#include "StudentManager.h"
#include <iomanip>

int getUserInput() {
    std::cout << "Choose from one of the following options (1-4):\n";
    std::cout << "1. Manage Students - add, update or remove\n";
    std::cout << "2. Display Students - view by name or GPA\n";
    std::cout << "3. Generate Report - overall gpa, gpa per student, all student grades";
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
        studentManager.displayStudents();

        std::cout << "Commands: add student [A], add grade to student [G <ID> <GRADE>], edit [E <ID>], delete [D <ID>]\n";
        std::cout << "Type your command: ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "A") {
            studentManager.addStudentWorkflow();
        } else {
            std::cout << "\nInvalid input, try again.\n";
        }
    }
}

void processInput(int input, StudentManager studentManager) {
    switch (input) {
        case 1:
            manageStudents(studentManager);
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
        processInput(input, studentManager);
    }


    return 0;
}