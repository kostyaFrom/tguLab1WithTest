#include <list>
#include <string>
#include <iostream>

using namespace std;

struct Student {
    string lastNameAndInit{};
    int groupNumber{};
    int studentPerformance[5] = {};
    float averageGrade{}; 
};

struct SortStudent {
public:
    bool operator() (const Student& first, const Student& second) {
        return (first.groupNumber < second.groupNumber);
    }
};

float countAverageGrade(int studentPerformance[]);

void checkCondition(std::list<Student>& students);

void requestStudentsInformation(Student& student, std::list<Student>& students);

void addStudentToList(Student& student, std::list<Student>& students);

void enterStudentsGrades(Student& student);

void checkEnteredStudentGrades(int& grade, Student& student);

void enterGroupNumber(Student& student);

void promptUserToEnterData(int i, Student& student);

int main() {

    list <Student> students;
    Student student;

    //processing students info
    requestStudentsInformation(student, students);

    // sorting =========================
    students.sort(SortStudent());

    checkCondition(students);

    return 0;
}


float countAverageGrade(int studentPerformance[]) {
    int result{};
    for (int i = 0; i < 5; i++) {
        result += studentPerformance[i];
    }
    return (float)result / 5;
}

void checkCondition(std::list<Student>& students)
{
    bool isPresent{ false };
    for (auto const& st : students) {
        if (st.averageGrade >= 4.0) {
            cout << " Last name: " << st.lastNameAndInit << " group number: " << st.groupNumber << endl;
            isPresent = true;
        }
    }

    if (!isPresent) {
        cout << "Students with average grade grater then 4 not exist." << endl;
    }
}

void requestStudentsInformation(Student& student, std::list<Student>& students)
{
    for (int i = 0; i < 5; i++) {

        //prompt to enter students informations
        promptUserToEnterData(i, student);

        //prompt to enter students group number
        enterGroupNumber(student);

        //prompt to enter student grades
        enterStudentsGrades(student);

        //add student to list
        addStudentToList(student, students);
    }
}

void addStudentToList(Student& student, std::list<Student>& students)
{
    student.averageGrade = countAverageGrade(student.studentPerformance);
    students.push_back(student);
    cin.get();
}

void enterStudentsGrades(Student& student) {
    cout << "Enter 5 grades of student: " << endl;
    int grade{ 0 };
    checkEnteredStudentGrades(grade, student);
}

void checkEnteredStudentGrades(int& grade, Student& student)
{
    for (int j = 0; j < 5; j++) {
        cout << j + 1 << " grade: " << endl;
        cin >> grade;
        if (grade > 5 || grade < 1) {
            cout << "Please enter grade between 1 and 5 inclusevli" << endl;
            j--;
        }
        else {
            student.studentPerformance[j] = grade;
        }
    }
}

void enterGroupNumber(Student& student)
{
    cout << "Enter group number: " << endl;
    cin >> student.groupNumber;
}

void promptUserToEnterData(int i, Student& student) {
    cout << "Enter data " << (i + 1) << " student: " << endl;
    cout << "LastName and Init: " << endl;
    getline(cin, student.lastNameAndInit);
}

