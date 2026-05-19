#include <iostream>
using namespace std;

class SensorBuffer {
    public:
        int* readings;
        int size;
        SensorBuffer(int n) {
            size = n;
            readings = new int[size];
            cout << "Constr invoked"<<endl;
            cout<<"Enter readings"<<endl;
            for (int i = 0; i < size; i++) {
                cin >> readings[i];
            }
        }
        ~SensorBuffer() {
            cout << "Destr invoked"<<endl;
            delete[] readings;
        }
        void show() {
            for (int i = 0; i < size; i++) {
                cout << readings[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    SensorBuffer* buf1 = new SensorBuffer(3);
    SensorBuffer* buf2 = new SensorBuffer(2);

    buf1->show();
    buf2->show();

    delete buf1;
    delete buf2;

    return 0;
}
