#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
private:
    string name;
    int id;
    double gpa;
    string major;

public:
    // Constructor
    Student(const string& studentName, int studentID, double studentGPA, const string& studentMajor) 
        : name(studentName), id(studentID), gpa(studentGPA), major(studentMajor) {}

    // Setter functions
    void setName(const string& studentName) {
        name = studentName;
    }

    void setID(int studentID) {
        id = studentID;
    }

    void setGPA(double studentGPA) {
        if (studentGPA >= 0.0 && studentGPA <= 4.0) {
            gpa = studentGPA;
        } else {
            cout << "Invalid GPA. Setting GPA to 0.\n";
            gpa = 0.0;
        }
    }

    void setMajor(const string& studentMajor) {
      major = studentMajor;
    }

    // Getter functions
    string getName() const {
        return name;
    }

    int getID() const {
        return id;
    }

    double getGPA() const {
        return gpa;
    }

    // Static function to compare two Student objects by GPA (descending)
    static bool compareByGPA(const Student& a, const Student& b) {
        return a.gpa > b.gpa;
    }

    string getMajor() const {
      return major;
    }
};

void displayStudentInfo(const Student& student) {
    cout << "Name: " << student.getName() << endl;
    cout << "ID: " << student.getID() << endl;
    cout << "GPA: " << student.getGPA() << endl;
    cout << "Major: " << student.getMajor() << endl << endl;
}

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    vector<Student> students;
    for (int i = 0; i < numStudents; ++i) {
        string name;
        int id;
        double gpa;
        string major;

        cout << "\nEnter information for student " << (i + 1) << ":\n";
        
        cout << "Name: ";
        cin.ignore(); // clear the newline left in the input buffer
        getline(cin, name);

        cout << "ID: ";
        cin >> id;

        do {
            cout << "GPA (0 - 4): ";
            cin >> gpa;
            if (gpa < 0.0 || gpa > 4.0) {
                cout << "Invalid GPA. Please enter a value between 0 and 4.\n";
            }
        } while (gpa < 0.0 || gpa > 4.0);

        cout << "Major: ";
        cin >> major;

        students.emplace_back(name, id, gpa, major);
    }

    // Display unsorted student information
    cout << "\nUnsorted Student Information:\n";
    for (const auto& student : students) {
        displayStudentInfo(student);
    }

    // Sort students by GPA in descending order
    sort(students.begin(), students.end(), Student::compareByGPA);

    // Display sorted student information
    cout << "\nStudent Information Sorted by GPA (Descending):\n";
    for (const auto& student : students) {
        displayStudentInfo(student);
    }

    return 0;
}