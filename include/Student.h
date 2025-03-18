#include <string>
#include <vector>

#ifndef STUDENT_H
#define STUDENT_H



class Student {
private:
    std::string name;
    int id;
    std::vector<int> grades;

public:
    Student(std::string name, int id);
    std::string getName();
    int getId();
    double getGPA();
    std::vector<int> getAllGrades();

    void addNewGrade(int grade);

};

#endif //STUDENT_H
