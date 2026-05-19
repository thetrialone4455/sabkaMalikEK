/*
A10. Write a program that handles runtime errors such as division by zero and 
invalid array index access using built-in exception handling mechanisms. 
In addition, define and implement custom exception classes to manage 
application-specific errors such as invalid input values or operation limits, 
ensuring clear error messages and safe program execution.
*/

#include <iostream>
#include <exception>
using namespace std;

class InvalidInputException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid input value!";
    }
};

class LimitExceededException : public exception {
public:
    const char* what() const noexcept override {
        return "Operation limit exceeded!";
    }
};

int main() {
    try {
        int a, b;
        cout << "Enter two numbers for division: ";
        cin >> a >> b;

        if (b == 0)
            throw runtime_error("Division by zero error!");

        cout << "Division Result: " << a / b << endl;

        int arr[5] = {10, 20, 30, 40, 50};
        int index;

        cout << "Enter array index (0-4): ";
        cin >> index;

        if (index < 0 || index >= 5)
            throw out_of_range("Invalid array index!");

        cout << "Array Value: " << arr[index] << endl;

        int input;
        cout << "Enter a positive number: ";
        cin >> input;

        if (input < 0)
            throw InvalidInputException();

        int value;
        cout << "Enter value (limit = 100): ";
        cin >> value;

        if (value > 100)
            throw LimitExceededException();

        cout << "Program executed successfully!" << endl;
    }

    catch (const out_of_range& e) {
        cout << "Array Error: " << e.what() << endl;
    }

    catch (const runtime_error& e) {
        cout << "Runtime Error: " << e.what() << endl;
    }

    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}