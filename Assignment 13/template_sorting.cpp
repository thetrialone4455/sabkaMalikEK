/*
PRBM STMT:
Write a C++ program that implements a generic function template to sort an array
of any data type using either Bubble Sort or Selection Sort.
The program should:
a) Accept an array of any type (such as int, float, char, etc.) from the user.
b) Use the generic function template to sort the array.
c) Display the sorted array.
*/

#include<iostream>
#include<limits>
using namespace std;

template<typename T>
void bubbleSort(T arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template<typename T>
void selectionSort(T arr[], int size){
    for(int i = 0; i < size - 1; i++){
        int minIndex = i;

        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        if(minIndex != i){
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

template<typename T>
void displayArray(T arr[], int size){
    cout << "Sorted Array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
void processArray(){
    int size;

    while(true){
        cout << "Enter number of elements: ";
        cin >> size;

        if(cin.fail() || size <= 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a positive integer.\n";
        }
        else{
            break;
        }
    }

    T arr[size];

    cout << "Enter elements:\n";

    for(int i = 0; i < size; i++){
        while(true){
            cout << "Element " << i + 1 << ": ";
            cin >> arr[i];

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter again.\n";
            }
            else{
                break;
            }
        }
    }

    int choice;

    while(true){
        cout << "\nChoose Sorting Method:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number.\n";
        }
        else{
            break;
        }
    }

    switch(choice){
        case 1:
            bubbleSort(arr, size);
            break;

        case 2:
            selectionSort(arr, size);
            break;

        default:
            cout << "Invalid Choice\n";
            return;
    }

    displayArray(arr, size);
}

int main(){
    int typeChoice;

    cout << "Sorting Program\n";
    cout << "Choose Data Type:\n";
    cout << "1. Integer\n";
    cout << "2. Float\n";
    cout << "3. Character\n";

    while(true){
        cout << "Enter choice: ";
        cin >> typeChoice;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number.\n";
        }
        else{
            break;
        }
    }

    switch(typeChoice){
        case 1:
            processArray<int>();
            break;

        case 2:
            processArray<float>();
            break;

        case 3:
            processArray<char>();
            break;

        default:
            cout << "Invalid Choice\n";
    }

    return 0;
}