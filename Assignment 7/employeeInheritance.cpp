/*
Design and implement a C++ program to demonstrate inheritance using the following 
employee hierarchy: 
Base Class: Employee with data members: Emp_name, Emp_id, Address, Mail_id, and 
Mobile_no. 
Derived Classes: Programmer, TeamLead, AssistantProjectManager, and 
ProjectManager. Each derived class should have an additional data member Basic Pay 
(BP). 
Salary components for all employees are calculated as: 
Dearness Allowance (DA): 52% of BP 
House Rent Allowance (HRA): 27% of BP 
Provident Fund (PF): 12% of BP 
Staff Club Fund: 0.1% of BP 
Implement member functions to calculate gross and net salary and generate pay slips 
for all employees.
*/
#include<iostream>
#include<limits>
#include<iomanip>
using namespace std;

class Employee{
public:
    string empName;
    static int empID;
    string address;
    string mailID;
    long long mobileNo;

    double da = 0.52;
    double hra = 0.27;
    double pf = 0.12;
    double scf = 0.001;

    double gross = 0;
    double net = 0;

    void calculateSalary(double bp){
        gross = bp + (bp * da) + (bp * hra);
        net = gross - (bp * pf) - (bp * scf);
    }

    void inputBasicDetails() {
        empID++;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (true) {
            cout << "Enter Employee Name: ";
            getline(cin, empName);

            bool valid = !empName.empty();
            for(char c : empName){
                if(!isalpha(c) && c!=' '){
                    valid = false;
                    break;
                }
            }

            if(valid) break;
            cout << "Invalid Name! Use letters only.\n";
        }

        while (true) {
            cout << "Enter Address: ";
            getline(cin, address);

            if (!address.empty()) break;
            cout << "Invalid Address! Try again.\n";
        }

        while (true) {
            cout << "Enter Mail ID: ";
            getline(cin, mailID);

            if (!mailID.empty() && mailID.find('@') != string::npos && mailID.find('.') != string::npos)
                break;

            cout << "Invalid Email! Try again.\n";
        }

        while (true) {
            cout << "Enter Mobile Number: ";
            cin >> mobileNo;

            if (!cin.fail() && mobileNo >= 1000000000 && mobileNo <= 9999999999)
                break;

            cout << "Invalid Mobile! Enter 10 digits.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void displaySlip(double bp, string role){
        cout << "\n\n";
        cout << "---------------------------------------------\n";
        cout << "               PAY SLIP\n";
        cout << "---------------------------------------------\n";
        cout << left << setw(20) << "Employee ID:" << empID << endl;
        cout << left << setw(20) << "Name:" << empName << endl;
        cout << left << setw(20) << "Role:" << role << endl;
        cout << left << setw(20) << "Address:" << address << endl;
        cout << left << setw(20) << "Mail ID:" << mailID << endl;
        cout << left << setw(20) << "Mobile No:" << mobileNo << endl;
        cout << "---------------------------------------------\n";

        cout << fixed << setprecision(2);
        cout << left << setw(20) << "Basic Pay:" << bp << endl;
        cout << left << setw(20) << "DA (52%):" << bp * da << endl;
        cout << left << setw(20) << "HRA (27%):" << bp * hra << endl;
        cout << left << setw(20) << "PF (12%):" << bp * pf << endl;
        cout << left << setw(20) << "Staff Fund (0.1%):" << bp * scf << endl;
        cout << "---------------------------------------------\n";
        cout << left << setw(20) << "Gross Salary:" << gross << endl;
        cout << left << setw(20) << "Net Salary:" << net << endl;
        cout << "---------------------------------------------\n\n";
    }
};

int Employee::empID = 1000;

class Programmer : public Employee{
public:
    double basicPay;

    void process(){
        inputBasicDetails();

        cout << "Enter Basic Pay: ";
        cin >> basicPay;

        calculateSalary(basicPay);
        displaySlip(basicPay, "Programmer");
    }
};

class TeamLead : public Employee{
public:
    double basicPay;

    void process(){
        inputBasicDetails();

        cout << "Enter Basic Pay: ";
        cin >> basicPay;

        calculateSalary(basicPay);
        displaySlip(basicPay, "Team Lead");
    }
};

class AssistantProjectManager : protected Employee{
public:
    double basicPay;

    void process(){
        inputBasicDetails();

        cout << "Enter Basic Pay: ";
        cin >> basicPay;

        calculateSalary(basicPay);
        displaySlip(basicPay, "Assistant Project Manager");
    }
};

class ProjectManager : protected Employee{
public:
    double basicPay;

    void process(){
        inputBasicDetails();

        cout << "Enter Basic Pay: ";
        cin >> basicPay;

        calculateSalary(basicPay);
        displaySlip(basicPay, "Project Manager");
    }
};


int main(){
    int choice;

    while(true){
        cout << "Select Department:\n";
        cout << "1. Programmer\n";
        cout << "2. Team Lead\n";
        cout << "3. Assistant Project Manager\n";
        cout << "4. Project Manager\n";
        cout << "0. Exit\n";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            continue;
        }

        switch(choice){
            case 1: {
                Programmer p;
                p.process();
                break;
            }
            case 2: {
                TeamLead t;
                t.process();
                break;
            }
            case 3: {
                AssistantProjectManager a;
                a.process();
                break;
            }
            case 4: {
                ProjectManager pm;
                pm.process();
                break;
            }
            case 0:
                cout << "Exiting Program\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}