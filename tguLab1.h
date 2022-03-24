#ifndef TGULAB1_STUDENT_H
#define TGULAB1_STUDENT_H

#include <list>
#include <string>
#include <iostream>

using namespace std;

struct Student {
    string lastNameAndInit{};
    int groupNumber{};
    int studentPerformance[5] = {};
    float averageGrade{};

    float countAverageGrade(int studentPerformance[]);

    void checkCondition(std::list<Student>& students);

    void requestStudentsInformation(Student& student, std::list<Student>& students);

    void addStudentToList(Student& student, std::list<Student>& students);

    void enterStudentsGrades(Student& student);

    void checkEnteredStudentGrades(int& grade, Student& student);

    void enterGroupNumber(Student& student);

    void promptUserToEnterData(int i, Student& student);


};

struct SortStudent {
public:
    bool operator() (const Student& first, const Student& second);
};

#endif