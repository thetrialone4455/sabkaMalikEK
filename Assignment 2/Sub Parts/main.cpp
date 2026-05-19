#include<iostream>
#include<string>
using namespace std;

class Student{
    public:
        int marks;
        string name;
        Student(){
            cout << "Normal constr is invoked" <<endl;
        }
        Student(int marks, string name){
            cout << "Parameterised constr is invoked" <<endl;
            this->marks = marks;
            this->name = name;
        }
        ~Student(){
            cout << "Destr is invoked" <<endl;
        }
        
        void display(){
            cout << this->marks <<endl;
            cout << this->name <<endl;
        }
};

int main(){
    Student* s1 = new Student();
    Student* s2 = new Student(28, "Om");
    
    s2->display();
    
    delete s1;
    delete s2;
}