/*
Write a C++ program to create a Student class with the following: 
Private members: Roll Number, Name, Marks of five subjects, Percentage, Result Division 
Public members: Parameterized constructor, destructor, functions to calculate percentage,
determine grade/division, and display student details

Implement a friend function comparePercentage() that takes two Student objects and displays the one 
with the higher percentage.
*/
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Student {
private:
    int roll;
    string name;
    float marks[5];
    float percentage;
    string division;

    int validRoll() {
        int x;
        while (true) {
            cin >> x;
            if (cin.fail() || x <= 0) {
                cout << "Enter valid roll: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else return x;
        }
    }

    string validName() {
        string n;
        while (true) {
            getline(cin, n);
            bool ok = true;
            if (n.empty()) ok = false;
            for (char c : n) {
                if (!(isalpha(c) || c == ' ')) {
                    ok = false;
                    break;
                }
            }
            if (ok) return n;
            cout << "Enter valid name: ";
        }
    }

    float validMarks() {
        float m;
        while (true) {
            cin >> m;
            if (cin.fail() || m < 0 || m > 100) {
                cout << "Enter marks 0-100: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else return m;
        }
    }

public:

    int getRoll() {
        return roll;
    }
    
    Student() {
        roll = 0;
        name = "";
        for (int i = 0; i < 5; i++){
            marks[i] = 0;
        }
        percentage = 0;
        division = "";
    }

    ~Student() {}

    void input(int existingRoll = -1) {
        cout << "Enter roll: ";
        
        while (true) {
            roll = validRoll();
            if (roll == existingRoll) {
                cout << "Roll already exists. Enter another: ";
            } else break;
        }

        cout << "Enter name: ";
        cin.ignore();
        name = validName();

        for (int i = 0; i < 5; i++) {
            cout << "Enter marks " << i + 1 << ": ";
            marks[i] = validMarks();
        }
    }

    void calculatePercentage() {
        float sum = 0;
        for (int i = 0; i < 5; i++) sum += marks[i];
        percentage = sum / 5.0;
    }

    void determineDivision() {
        if (percentage >= 60) division = "First";
        else if (percentage >= 50) division = "Second";
        else if (percentage >= 40) division = "Third";
        else division = "Fail";
    }

    void display() {
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++) cout << marks[i] << " ";
        cout << endl;
        cout << "Percentage: " << percentage << endl;
        cout << "Division: " << division << endl;
    }

    friend void comparePercentage(Student s1, Student s2);
};

void comparePercentage(Student s1, Student s2) {
    if (s1.percentage > s2.percentage) {
        cout << "Higher Percentage Student:\n";
        s1.display();
    } else if (s2.percentage > s1.percentage) {
        cout << "Higher Percentage Student:\n";
        s2.display();
    } else {
        cout << "Both have same percentage\n";
        s1.display();
        s2.display();
    }
}

int main() {
    Student s1, s2;

    cout << "Enter details of student 1\n";
    s1.input();
    s1.calculatePercentage();
    s1.determineDivision();

    cout << "Enter details of student 2\n";
    s2.input(s1.getRoll());   // pass existing roll
    s2.calculatePercentage();
    s2.determineDivision();

    comparePercentage(s1, s2);

    return 0;
}