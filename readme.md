# Student Grade Management System: A C++ Practice Project

This project is dedicated towards helping me solidify my C++ fundamentals by working with classes, file handling, 
dynamic memory, and STL containers. It will reinforce concepts like input validation, sorting and searching.

### Project Overview

This is a command-line application that allows users to store student records, update grades, and generate reports. 
The program will use classes to represent students, file handling to save/load data, and STL containers to manage 
student records efficiently.

### System Design & Technical Specifications

**Components**
- **Student Class**
  - Stores student details like name, ID and grades
  - Provides functions to update student information
- **StudentManager Class**
  - Manages a collection of students using vector
  - Provides functions to add, remove or update students
  - Loads/saves student data from a file
- **Report Generator**
  - Calculates student GPA
  - Displays all students and their grades
  - Sorts students by name, ID or GPA

**Functional Requirements**
- **Student Management**
  - Adds a new student (name, ID, grades)
  - Updates grades for a student
  - Delete a student record
  - Display all students
- **Report Generation**
  - Show all students and their grades
  - Calculate and display GPA for each student
  - Sort students by name, ID or GPA
- **File Handling**
  - Save student records to a file
  - Load student records on startup