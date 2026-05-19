/*
A bank has multiple customer accounts.Each account stores sensitive information like balance and PIN, 
which must remain private. A bank manager needs access to this private information to perform certain 
operations like checking balance and updating it.
*/
#include<iostream>
#include<limits>
#include<iomanip>
using namespace std;

class Accounts;

class Bank{
    public:
        int minBalance;
        Accounts* acc;
        int total;

        Bank(){
            minBalance = 500;
            acc = new Accounts[10];
            total = 0;
        }
};

class Manager;

class Accounts{
    friend class Manager;
    private:
        float balance;
        int PIN;
        int id;

    public:
        string accountHolder;
        static int accountID;
        Bank* bank;

        int getID(){ 
            return id; 
        }

        float getBalance(){ 
            return balance; 
        }

        float validAmount(){
            float x;
            while(true){
                cin>>x;
                if(cin.fail() || x < 0){
                    cout<<"Invalid amount. Re-enter: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else 
                    return x;
            }
        }

        string validName(){
            string name;
            while(true){
                getline(cin, name);

                bool ok = !name.empty();
                for(char c : name){
                    if(!(isalpha(c) || c==' ')){
                        ok = false;
                        break;
                    }
                }

                if(ok) 
                    return name;

                cout<<"Invalid name. Only alphabets allowed. Re-enter: ";
            }
        }

        int validPIN(){
            int p;
            while(true){
                cin>>p;
                if(cin.fail() || p<1000 || p>9999){
                    cout<<"Enter 4-digit PIN: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else 
                    return p;
            }
        }

        int getValidID(Bank &bank){
            int searchID;
            while(true){
                cout<<"Enter account ID: ";
                cin>>searchID;

                if(cin.fail()){
                    cout<<"Invalid ID.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                for(int i=0;i<bank.total;i++){
                    if(bank.acc[i].getID() == searchID)
                        return searchID;
                }

                cout<<"Account not found. Try again.\n";
            }
        }

        void createAccount(){
            id = accountID++;

            cout<<"Enter Name: ";
            cin.ignore();
            accountHolder = validName();

            cout<<"Enter Initial Balance (>=500): ";
            while(true){
                balance = validAmount();
                if(balance < bank->minBalance)
                    cout<<"Minimum balance required. Re-enter: ";
                else 
                    break;
            }

            cout<<"Set PIN: ";
            PIN = validPIN();

            cout<<"Account created! ID: "<<id<<endl;
        }

        bool verify(){
            int p;
            cout<<"Enter PIN: ";
            cin>>p;
            return p == PIN;
        }

        void viewBalance(){
            if(verify())
                cout<<"\nBalance: "<<balance<<endl;
            else
                cout<<"Wrong PIN\n";
        }

        void withdraw(){
            if(!verify()){
                cout<<"Wrong PIN\n";
                return;
            }

            cout<<"Enter amount: ";
            float amt = validAmount();

            if(balance - amt < bank->minBalance){
                cout<<"Cannot go below minimum balance\n";
                return;
            }

            balance -= amt;
            cout<<"Withdraw successful\n";
        }

        void resetPIN(){
            if(!verify()){
                cout<<"Wrong PIN\n";
                return;
            }

            cout<<"Enter new PIN: ";
            PIN = validPIN();
            cout<<"PIN updated\n";
        }
};

class Manager{
private:
    int managerPIN = 9999;

    bool authenticate(){
        int p;
        cout<<"Enter Manager PIN: ";
        cin>>p;
        if(p == managerPIN) return true;

        cout<<"Wrong Manager PIN\n";
        return false;
    }

public:
    void viewAll(Bank &b){
        if(!authenticate()) return;

        cout << "\n--------- MANAGER VIEW ---------\n";
        cout << setw(10) << "ID"
             << setw(20) << "Name"
             << setw(15) << "Balance\n";

        cout << string(45, '-') << endl;

        for(int i = 0; i < b.total; i++){
            cout << setw(10) << b.acc[i].id
                 << setw(20) << b.acc[i].accountHolder
                 << setw(15) << fixed << setprecision(2) << b.acc[i].balance
                 << endl;
        }
    }
};

int Accounts::accountID = 1;

int main(){
    Bank bank;
    Manager m;
    int flag;

    do{
        cout<<"\n1.Create\n2.View\n3.Withdraw\n4.Reset PIN\n5.Manager\n0.Exit\n";
        cout<<"Choice: ";
        cin>>flag;

        switch(flag){

        case 1:
            if(bank.total>=10){
                cout<<"Bank full\n";
                break;
            }
            bank.acc[bank.total].bank = &bank;
            bank.acc[bank.total].createAccount();
            bank.total++;
            break;

        case 2:{
            if(bank.total==0){ 
                cout<<"No accounts\n"; 
                break; 
            }

            int id = bank.acc[0].getValidID(bank);
            for(int i=0;i<bank.total;i++){
                if(bank.acc[i].getID()==id){
                    bank.acc[i].viewBalance();
                }
            }
            break;
        }

        case 3:{
            if(bank.total==0){ 
                cout<<"No accounts\n"; 
                break; 
            }

            int id = bank.acc[0].getValidID(bank);
            for(int i=0;i<bank.total;i++){
                if(bank.acc[i].getID()==id){
                    bank.acc[i].withdraw();
                }
            }
            break;
        }

        case 4:{
            if(bank.total==0){ 
                cout<<"No accounts\n"; 
                break; 
            }

            int id = bank.acc[0].getValidID(bank);
            for(int i=0;i<bank.total;i++){
                if(bank.acc[i].getID()==id){
                    bank.acc[i].resetPIN();
                }
            }
            break;
        }

        case 5:
            m.viewAll(bank);
            break;

        }

    }while(flag!=0);
}