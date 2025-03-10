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
    std::string getName();
    int getId();
    int getGPA();
    std::vector<int> getAllGrades();

    void updateName(std::string newName);
    void addNewGrade(int grade);
    int removeGradeByIndex(int index);

Student::Student(std::string name, int id);
};

#endif //STUDENT_H
