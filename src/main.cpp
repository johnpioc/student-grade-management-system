#include <iostream>
#include "StudentManager.h"

int getUserInput() {
    std::cout << "Choose from one of the following options (1-4):\n";
    std::cout << "1. Manage Students - add, update or remove\n";
    std::cout << "2. Display Students - view by name or GPA\n";
    std::cout << "3. Generate Report - overall gpa, gpa per student, all student grades";
    std::cout << "4. quit the application\n\n";

    int input;
    std::cout << "Enter option: ";
    std::cin >> input;

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
    }

    return 0;
}