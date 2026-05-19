#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

class Book
{
    public:
    static int totalBook;
    string b_name, b_author;
    float price;

    int b_id;

    bool isValidText(string s)
    {
        if (s.empty())
            return false;

        for (char c : s)
        {
            if (!isalpha(c) && c != ' ')
                return false;
        }
        return true;
    }

    void get_details()
    {
        while (true)
        {
            cout << "Enter book id: ";
            cin >> b_id;

            if (cin.fail() || b_id <= 0)
            {
                cout << "Invalid ID. Must be positive and non-zero.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        do
        {
            cout << "Enter Book name: ";
            getline(cin, b_name);

            if (!isValidText(b_name)){
                cout << "Invalid book name\n";}

        } while (!isValidText(b_name));

        do
        {
            cout << "Enter Author name: ";
            getline(cin, b_author);

            if (!isValidText(b_author)){
                cout << "Invalid author name\n";}

        } while (!isValidText(b_author));
    }

    void get_price()
    {
        while (true)
        {
            cout << "Enter price: ";
            cin >> price;

            if (cin.fail() || price < 100)
            {
                cout << "Invalid input Enter again(min 100)\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }

        cout << endl;
    }

    void print_row()
    {
        cout << setw(10) << left << b_id
             << setw(20) << left << b_name
             << setw(20) << left << b_author
             << setw(10) << right << fixed << setprecision(2) << price
             << endl;
    }

    float get_price_val()
    {
        return price;
    }

    static int get_Total_BookCount(){
        return Book::totalBook;
    }
    void increment_Total_BookCount(){
         totalBook++;
    }
};

int Book::totalBook = 0;

int main()
{
    Book b[25];
    int n = 0;
    int limit;

    cout << "Enter total number of books (max 25): ";
    cin >> limit;

    if (cin.fail() || limit < 1 || limit > 25)
    {
        cout << "Invalid number of books\n";
        return 0;
    }


    while (n < limit)
    {
        b[n].get_details();
        b[n].get_price();
        b[n].increment_Total_BookCount();
        n++;
    }

    if (n == 0)
    {
        cout << "No books entered.\n";
        return 0;
    }

    cout << "\n"
         << setw(10) << left << "Book ID"
         << setw(20) << left << "Book Name"
         << setw(20) << left << "Author"
         << setw(10) << left << "Price" << endl;

    cout << string(60, '-') << endl;

    float total = 0;
    for (int i = 0; i < n; i++)
    {
        b[i].print_row();
        total += b[i].get_price_val();
    }

    cout << "\nTotal Price: " << setprecision(2) << total << endl;
    cout << "\nTotal Books: " << Book::get_Total_BookCount() << endl;

    return 0;
}