#include <iostream>
#include <limits>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    void input() {
        cout << "Enter real part: ";
        while (!(cin >> real)){
            cout << "Invalid input! Enter numeric value: "<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter imaginary part: ";
        while (!(cin >> imag)){
            cout << "Invalid input! Enter numeric value: "<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void display(){
        cout << real;
        if (imag >= 0){
            cout << " + " << imag << "i"<<endl;
        }
        else{
            cout << " - " << -imag << "i"<<endl;
        }
    }

    Complex operator+(Complex& c){
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(Complex& c){
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(Complex& c){
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;
        return Complex(r, i);
    }
};

int main() {
    Complex c1, c2;

    cout << "Enter first complex number:"<<endl;
    c1.input();

    cout << "Enter second complex number:"<<endl;
    c2.input();

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    cout << "First Complex: "<<endl;
    c1.display();

    cout << "Second Complex: "<<endl;
    c2.display();

    cout << "Addition: "<<endl;
    sum.display();

    cout << "Subtraction: "<<endl;
    diff.display();

    cout << "Multiplication: "<<endl;
    prod.display();

    cout << endl;
    return 0;
}