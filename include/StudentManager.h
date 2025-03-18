#include <vector>
#include "Student.h"

#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H



class StudentManager {
private:
    std::vector<Student> students;

public:
    void addStudent(Student newStudent);
    std::vector<Student> getAllStudents();
    void removeStudentById(int id);
    int getNumOfStudents();
    Student* getStudentById(int id);
    void displayStudents(std::vector<Student> students);
    void addStudentWorkflow();
    void saveToFile();
    void readFromFile();
    void createReport();
};



#endif //STUDENTMANAGER_H
