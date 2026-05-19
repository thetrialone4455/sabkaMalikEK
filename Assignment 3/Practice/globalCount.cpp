#include <iostream>

using namespace std;

class Globle{
    public:
        static int count;

        void show(){
            cout << Globle::count << endl;
        }
};  

int Globle::count = 0;

int main(){
    Globle g;
    Globle g1;

    g.count = 2;
    g.show();
    
    cout << g1.count  << endl;
    g1.count = 5;
    
    cout << g.count << endl;
    cout << g1.count;
    return 0;
}