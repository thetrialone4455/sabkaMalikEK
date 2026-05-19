/*
Design a base class Shape with two double-type data members to represent the 
dimensions of the shape. Include member functions to input the dimensions and a 
pure virtual function compute_area() for calculating the area. 
Derive two classes: Triangle and Rectangle from Shape and override the 
compute_area() function to calculate the area according to the specific shape. 
Write a program that: 
a) Accepts the dimensions of a triangle or rectangle from the user. 
b) Uses dynamic binding to call the appropriate compute_area() function.  
c) Displays the calculated area of the shape.
*/

#include<iostream>
#include<iomanip>
#include<limits>
using namespace std;

class Shape {
    protected:
        double dim1, dim2;

    public:
        void inputDimensions(){
            while(true){
                cout << "Enter first dimension: ";
                cin >> dim1;
                if(!cin.fail() && dim1 > 0){
                    break;
                }
                cout << "Invalid input! Enter a positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            while(true){
                cout << "Enter second dimension: ";
                cin >> dim2;
                if(!cin.fail() && dim2 > 0){
                    break;
                }
                cout << "Invalid input! Enter a positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        virtual double compute_area() = 0;        // pure virtual

        virtual void displayArea(){
            cout << "Area: " << compute_area() << endl;
        }
};

class Triangle : public Shape{
    public:
        double compute_area() override{
            return 0.5 * dim1 * dim2;
        }
};

class Rectangle : public Shape{
    public:
        double compute_area() override{
            return dim1 * dim2;
        }
};

int main(){
    int choice;
    Shape* shape;

    while(true){
        cout << "\nSelect Shape:\n";
        cout << "1. Triangle\n";
        cout << "2. Rectangle\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            continue;
        }

        switch(choice){
            case 1:
                shape = new Triangle();
                shape->inputDimensions();
                cout << "\n--- Triangle ---\n";
                shape->displayArea();
                break;

            case 2:
                shape = new Rectangle();
                shape->inputDimensions();
                cout << "\n--- Rectangle ---\n";
                shape->displayArea();
                break;

            case 0:
                cout << "Exiting Program\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}