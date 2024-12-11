#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int marks1, marks2, marks3;
    float percentage;
    char grade;

public:
    // Member function to input student details
    void inputDetails() {
        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter marks for subject 1: ";
        cin >> marks1;
        cout << "Enter marks for subject 2: ";
        cin >> marks2;
        cout << "Enter marks for subject 3: ";
        cin >> marks3;

        calculatePercentageAndGrade(); // Automatically calculate percentage and grade
    }

    // Member function to calculate percentage and grade
    void calculatePercentageAndGrade() {
        int totalMarks = marks1 + marks2 + marks3;
        percentage = static_cast<float>(totalMarks) / 3;

        if (percentage >= 90) grade = 'A';
        else if (percentage >= 75) grade = 'B';
        else if (percentage >= 50) grade = 'C';
        else grade = 'F';
    }

    // Member function to display student details
    void displayDetails() {
        cout << "Student Name: " << name << endl;
        cout << "Marks: " << marks1 << ", " << marks2 << ", " << marks3 << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student student;

    // Input details, calculate grade, and display the details
    student.inputDetails();
    student.displayDetails();

    return 0;
}
