/* 
PRBM STMT:
Code for unary operator + overloading.
*/
#include<iostream>
#include<limits>
using namespace std;

class Number {
    public:
        int value;

        int validInput(){
            int x;
            while(true){
                cin >> x;

                if (cin.fail()){
                    cout << "Enter valid integer: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } 
                else{
                    return x;
                }
            }
        }

        void input(){
            cout << "Enter number: ";
            while(true){
                cin >> value;
                if (cin.fail()){
                    cout << "Enter valid integer: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else{
                    break;
                }
            }
        }

        void display(){
            cout << "Value: " << value << endl;
        }

        Number operator+(const Number& obj){
            Number temp;
            temp.value = value + obj.value;
            return temp;
        }
};

int main(){
    Number n1, n2, result;

    cout << "Enter first number"<<endl;
    n1.input();

    cout << "Enter second number"<<endl;
    n2.input();

    result = n1 + n2;  

    cout << "Result:\n";
    result.display();

    return 0;
}