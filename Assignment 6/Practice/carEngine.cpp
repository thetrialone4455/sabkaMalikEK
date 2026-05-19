#include <iostream>
using namespace std;

class Engine{
    public:
        void startEngine(){
            cout << "Engine started." << endl;
        }
};

class Car{
    public:
        Engine e;

        void startCar(){
            e.startEngine();
            cout << "Car started" << endl;
        }
};

int main(){
    Car obj;
    obj.startCar();
    return 0;
}