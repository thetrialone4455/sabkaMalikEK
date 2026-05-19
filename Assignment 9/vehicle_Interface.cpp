/*
PRBM STMT:
Design and implement an interface for Vehicles to represent common functionalities.

Vehicles:
- Bicycle
- Bike
- Car

Common Functionalities:
- gearChange()
- speedUp()
- applyBrakes()

Create an interface Vehicle and implement it in all classes.
*/

#include<iostream>
using namespace std;

class Vehicle{
    public:
        virtual void gearChange() = 0;
        virtual void speedUp() = 0;
        virtual void applyBrakes() = 0;

        virtual ~Vehicle(){}
};

class Bicycle : public Vehicle{
    public:
        void gearChange() override{
            cout << "Bicycle gear changed manually.\n";
        }

        void speedUp() override{
            cout << "Bicycle speed increased by pedaling faster.\n";
        }

        void applyBrakes() override{
            cout << "Bicycle brakes applied using hand brakes.\n";
        }
};

class Bike : public Vehicle{
    public:
        void gearChange() override{
            cout << "Bike gear changed using gearbox.\n";
        }

        void speedUp() override{
            cout << "Bike speed increased using accelerator.\n";
        }

        void applyBrakes() override{
            cout << "Bike brakes applied using disc brakes.\n";
        }
};

class Car : public Vehicle{
    public:
        void gearChange() override{
            cout << "Car gear changed using transmission system.\n";
        }

        void speedUp() override{
            cout << "Car speed increased by pressing accelerator.\n";
        }

        void applyBrakes() override{
            cout << "Car brakes applied using brake pedal.\n";
        }
};

int main(){
    int choice;

    cout << "--- Vehicle Interface Program ---\n";
    cout << "1. Bicycle\n";
    cout << "2. Bike\n";
    cout << "3. Car\n";
    cout << "Enter choice: ";
    cin >> choice;

    Vehicle* v = nullptr;

    switch(choice){
        case 1:
            v = new Bicycle();
            break;

        case 2:
            v = new Bike();
            break;

        case 3:
            v = new Car();
            break;

        default:
            cout << "Invalid Choice\n";
            return 0;
    }

    cout << "\nVehicle Operations:\n";

    v->gearChange();
    v->speedUp();
    v->applyBrakes();

    delete v;

    return 0;
}