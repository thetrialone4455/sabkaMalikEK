/*
Implement a generic C++ program using a C++ Standard Library collection class
(such as vector or list) to count the number of elements in the collection that satisfy a specific property. 

Example properties include:
Even numbers
Odd numbers
Prime numbers
Palindromes

The program should:
Allow the user to input the elements of the collection. Allow the user to choose a property to count. Display the total count of elements satisfying the selected property.
*/

#include<iostream>
#include<vector>
#include<limits>
using namespace std;

void insertElements(vector<int>& v){
    int value;

    while(true){
        cout << "Enter element: ";
        cin >> value;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer.\n";
        } 
        else{
            v.push_back(value);
            break;
        }
    }
}

void evenOddCheck(const vector<int>& v){
    if(v.empty()){
        cout << "Vector is empty.\n";
        return;
    }
    for(int num : v){
        if(num % 2 == 0){
            cout << num << " : Yes" << endl;
        } 
        else{
            cout << num << " : No" << endl;
        }
    }
}

void palindromeCheck(const vector<int>& v){
    if(v.empty()){
        cout << "Vector is empty.\n";
        return;
    }
    int left = 0;
    int right = v.size() - 1;

    while(left < right){
        if (v[left] != v[right]) {
            cout << "Not Palindrome\n";
            return;
        }
        left++;
        right--;
    }

    cout << "Palindrome\n";
}

void palindromeCheckChars(){
    vector<char> c;
    int n;
    char ch;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters:\n";
    for(int i = 0; i < n; i++){
        cin >> ch;
        c.push_back(ch);
    }

    int left = 0;
    int right = c.size() - 1;

    while(left < right){
        if(c[left] != c[right]){
            cout << "Not Palindrome\n";
            return;
        }
        left++;
        right--;
    }

    cout << "Palindrome\n";
}

void primeCheck(const vector<int>& v){
    if(v.empty()){
        cout << "Vector is empty.\n";
        return;
    }
    for(int num : v){
        bool prime = true;

        if(num < 2){
            prime = false;
        } 
        else{
            for(int i = 2; i < num; i++){
                if(num % i == 0){
                    prime = false;
                    break;
                }
            }
        }

        if(prime){
            cout << num << " : Yes" << endl;
        }
        else{
            cout << num << " : No" << endl;
        }
    }
}

void removeElement(vector<int>& v){
    if(v.empty()){
        cout << "Vector is empty.\n";
        return;
    }

    int value;
    cout << "Enter element to remove: ";
    cin >> value;

    for(int i = 0; i < v.size(); i++){
        if(v[i] == value){
            v.erase(v.begin() + i);
            cout << "Element removed.\n";
            return;
        }
    }

    cout << "Element not found.\n";
}

void displayElements(const vector<int>& v){
    if(v.empty()){
        cout << "Vector is empty.\n";
        return;
    }

    cout << "Vector elements: ";
    for(int num : v){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v;
    int choice;

    do{
        cout << "\n--- MENU ---\n";
        cout << "1. Insert Elements\n";
        cout << "2. Even/Odd Check\n";
        cout << "3. Palindrome Check\n";
        cout << "4. Char Palindrome Check\n";
        cout << "5. Prime Check\n";
        cout << "6. Remove Element\n";
        cout << "7. Display Element\n";
        cout << "8. Exit\n";

        while(true){
            cout << "Enter choice: ";
            cin >> choice;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n";
            } 
            else{
                break;
            }
        }

        switch(choice){
            case 1:
                insertElements(v);
                break;

            case 2:
                evenOddCheck(v);
                break;

            case 3:
                palindromeCheck(v);
                break;

            case 4:
                palindromeCheckChars();
                break;

            case 5:
                primeCheck(v);
                break;

            case 6:
                removeElement(v);
                break;

            case 7:
                displayElements(v);
                break;

            case 8:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }
    }while(choice != 8);

    return 0;
}