/*
Write a program to create a Book class and extend it by using dynamic memory allocation. 
Use the new keyword and object pointers to create Book objects dynamically. The program 
should allow the user to: Input details of one or more books. Display the book details. 
Demonstrate the use of dynamic memory allocation for objects..
*/

#include<iostream>
#include<limits>
using namespace std;

class Book{
    private:
        string title;
        string author;
        float price;

    public:
        void inputDetails(){
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);

            cout << "Enter Author Name: ";
            getline(cin, author);

            while(true){
                cout << "Enter Price: ";
                cin >> price;

                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Enter numeric value.\n";
                }
                else if(price < 0){
                    cout << "Price cannot be negative.\n";
                }
                else{
                    break;
                }
            }
        }

        void displayDetails(){
            cout << "\nBook Details\n";
            cout << "Title  : " << title << endl;
            cout << "Author : " << author << endl;
            cout << "Price  : " << price << endl;
        }
};

int main(){
    int n;

    while(true){
        cout << "Enter number of books: ";
        cin >> n;

        if(cin.fail() || n <= 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter positive integer.\n";
        }
        else{
            break;
        }
    }

    Book* books = new Book[n];

    for(int i = 0; i < n; i++){
        cout << "\nEnter details for Book " << i + 1 << endl;
        books[i].inputDetails();
    }

    cout << "\n--- Book Records ---\n";

    for(int i = 0; i < n; i++){
        books[i].displayDetails();
    }

    delete[] books;

    return 0;
}