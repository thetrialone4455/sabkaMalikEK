#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

class Book{
private:
    string bookName, bauthor;
    double price;

public:
    int bookid;

    void getdetail(){
        while (true){
            cout << "Enter book id or enter 0 to exit: ";
            cin >> bookid;

            if (cin.fail() || bookid < 0){
                cout << "Invalid input. Enter again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (bookid == 0)
                return;

            break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        do{
            cout << "Enter Book name: ";
            getline(cin, bookName);
        }while (bookName.empty());

        do{
            cout << "Enter Author name: ";
            getline(cin, bauthor);
        }while (bauthor.empty());
    }

    void get_price(){
        while (true){
            cout << "Enter price: ";
            cin >> price;

            if (cin.fail() || price < 0){
                cout << "Invalid input. Enter again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else{
                break;
            }
        }
    }

    void print(){
        cout << setw(10) << left << bookid
             << setw(20) << left << bookName
             << setw(20) << left << bauthor
             << setw(10) << right << fixed << setprecision(2) << price
             << endl;
    }

    double getprice(){
        return price;
    }
};

int main(){
    Book b[50];
    int n = 0;

    while (n < 50){
        b[n].getdetail();
        if (b[n].bookid == 0)
            break;

        b[n].get_price();
        n++;
    }

    if (n == 0){
        cout << "No books entered.\n";
        return 0;
    }

    cout << "\n"
         << setw(10) << left << "Book ID"
         << setw(20) << left << "Book Name"
         << setw(20) << left << "Author"
         << setw(10) << left << "Price" << endl;

    cout << string(60, '-') << endl;

    double total = 0;
    for(int i = 0; i < n; i++){
        b[i].print();
        total += b[i].getprice();
    }

    cout << "\nTotal Price: " << fixed << setprecision(2) << total << endl;
}
