/* 
PRBM STMT:
Code for unary operator ++ overloading in postfix and prefix ways
*/

#include<iostream>
#include<limits>
using namespace std;

class Number{
public:
    int value;

    void input(){
        cout << "Enter number: ";
        while(true){
            cin >> value;
            if(cin.fail()){
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

    Number operator++(){
        ++value;        
        return *this;   
    }

    Number operator++(int){
        Number temp = *this;  
        value++;              
        return temp;          
    }
};

int main(){
    Number n1, result;

    n1.input();

    cout << "Actual object value:"<<endl;
    n1.display();

    cout << "Using prefix ++"<<endl;
    result = ++n1;
    result.display();
    
    cout << "Current object value:"<<endl;
    n1.display();

    cout << "Using postfix ++"<<endl;
    result = n1++;
    result.display();

    cout << "Final object value:"<<endl;
    n1.display();

    return 0;
}