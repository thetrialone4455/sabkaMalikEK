/*
Design and implement a C++ program to model a banking system where the class 
BankAccount keeps track of the total number of accounts created and the total 
balance across all accounts. Use static data members to maintain these values and 
static member functions to retrieve and display them. Additionally, implement a 
member function in the BankAccount class that takes another BankAccount object as 
an argument and displays 

the two account balances in ascending order.
*/
#include<iostream>
#include<limits>
#include<string>
using namespace std;

class BankAccount{
public:
    double balance;
    static int totalAccounts;
    static double totalBalance;

    BankAccount(){
        balance = 500;
    }

    bool isNumber(string s){
        int dots = 0;

        for(char c : s){
            if(isdigit(c)){
                continue;
            }

            if(c == '.' && dots == 0){
                dots++;
                continue;
            }
            return false;
        }
        return true;
    }

    void input(){
        string s;
        double b;

        while(true){
            cout << "Enter balance: ";
            cin >> s;

            if(!isNumber(s)){
                cout << "Invalid input. Enter numeric value.\n";
                continue;
            }

            b = stod(s);

            if(b < 0){
                cout << "Balance cannot be negative.\n";
                continue;
            }

            balance = b;
            totalAccounts++;
            totalBalance += balance;
            break;
        }
    }

    void display(){
        cout << "Balance: " << balance << endl;
    }

    void showAscending(const BankAccount& other){
        if(balance < other.balance)
            cout << balance << " " << other.balance << endl;
        else
            cout << other.balance << " " << balance << endl;
    }

    static void showTotals(){
        cout << "\nTotal accounts: " << totalAccounts << endl;
        cout << "Total balance: " << totalBalance << endl;
    }
};

int BankAccount::totalAccounts = 0;
double BankAccount::totalBalance = 0;

int main(){
    int n;

    while(true){
        cout << "Enter number of accounts: ";
        cin >> n;

        if(cin.fail()){
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if(n <= 0){
            cout << "Must be positive.\n";
            continue;
        }
        break;
    }

    BankAccount* arr = new BankAccount[n];

    for(int i = 0; i < n; i++){
        cout << "\nAccount " << i+1 << endl;
        arr[i].input();
    }

    cout << "\n--- Accounts ---\n";
    for(int i = 0; i < n; i++){
        arr[i].display();
    }

    BankAccount::showTotals();

    if(n >= 2){
        cout << "Ascending of first two: ";
        arr[0].showAscending(arr[1]);
    }

    delete[] arr;
    return 0;
}