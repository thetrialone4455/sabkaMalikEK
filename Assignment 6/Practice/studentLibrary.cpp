#include<iostream>
#include<string>
using namespace std;

class Student{
    public:
        string name;
        Student(string s){
            name = s;
        }
        void Hi(){
            cout << "from student" << endl;
        }
};

class Library{
    Student* s;
    public:
        void hello(Student* st ){
            s = st;
            cout << "from library. "<< s->name << endl;
        }
};

int main(){
    Library l;
    Student s1("rohan");
    l.hello(&s1);
    return 0;
}