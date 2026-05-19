/*
Write a C++ program to implement a class Book with suitable data members. Use 
constructors to initialize book details and a destructor to indicate object destruction, 
thereby demonstrating the concepts of objects, classes, constructors, and destructors.
*/
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

class Books{
public:
    long *bookID;
    long *price;
    string *authorName;

    Books(){
        bookID = new long;
        price = new long;
        authorName = new string;

        *bookID = 1;
        *price = 1000;
        *authorName = "Unknown";
    }

    ~Books(){
        delete bookID;
        delete price;
        delete authorName;
    }

    void input(){
        long id;
        long p;
        string name;

        while (true){
            cout << "Enter Book ID: ";
            cin >> id;

            if (cin.fail()){
                cout << "Invalid input. Enter numeric value.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (id <= 0){
                cout << "Book ID must be positive.\n";
                continue;
            }

            break;
        }

        while(true){
            cout << "Enter Price: ";
            cin >> p;

            if (cin.fail()){
                cout << "Invalid input. Enter numeric value.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (p <= 0){
                cout << "Price must be positive.\n";
                continue;
            }

            break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while(true){
            cout << "Enter Author Name: ";
            getline(cin, name);

            if (name.length() == 0){
                cout << "Author name cannot be empty.\n";
                continue;
            }

            break;
        }

        *bookID = id;
        *price = p;
        *authorName = name;
    }

    void displayRow(){
        cout << setw(12) << left << *bookID
             << setw(25) << left << *authorName
             << setw(15) << right << *price
             << endl;
    }
};

int main(){
    int n;
    while(true){
        cout << "Enter number of books: ";
        cin >> n;

        if (cin.fail()){
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (n <= 0){
            cout << "Number must be positive.\n";
            continue;
        }
        break;
    }

    Books *arr = new Books[n];

    for (int i = 0; i < n; i++){
        cout << "\nEnter details for book " << i + 1 << endl;
        arr[i].input();
    }

    cout << "\n\n";
    cout << setw(12) << left << "Book ID"
         << setw(25) << left << "Author Name"
         << setw(15) << right << "Price"
         << endl;

    cout << string(52, '-') << endl;

    for (int i = 0; i < n; i++){
        arr[i].displayRow();
    }

    delete[] arr;
    return 0;
}