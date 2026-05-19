#include<iostream>
#include<iomanip>
#include<limits>
#include<cctype>
using namespace std;

class Publication{
    public:
        string title;
        double price;
        int copies;

        void getData(){
            while(true){
                cout<<"Enter Title: ";
                getline(cin,title);
                
                bool valid = !title.empty();
                for(char c : title){
                    if(!isalpha(c) && c!=' '){
                        valid=false;
                        break;
                    }
                }
                
                if(valid) break;
                cout<<"Invalid Title! Letters only.\n";
            }
            
            while(true){
                cout<<"Enter Price: ";
                cin>>price;
                
                if(!cin.fail() && price>0)
                break;
                
                cout<<"Invalid Price!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            
            while(true){
                cout<<"Enter Copies Sold: ";
                cin>>copies;
                
                if(!cin.fail() && copies>=0)
                break;
                
                cout<<"Invalid Copies!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }
        
        double saleCopy(){
            return price * copies;
        }
};

class Book{
    public:
        Publication p;
        string author;
        int orderedCopies;
        
        void getData(){
            p.getData();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            while(true){
                cout<<"Enter Author: ";
                getline(cin,author);
                
                bool valid = !author.empty();
                
                for(char c:author){
                    if(!isalpha(c) && c!=' '){
                        valid=false;
                        break;
                    }
                }
                
                if(valid) break;
                
                cout<<"Invalid Author! Letters only.\n";
            }
        }
        
        void orderCopies(){
            while(true){
                cout<<"Enter Copies Ordered: ";
                cin>>orderedCopies;
                
                if(!cin.fail() && orderedCopies>=0)
                break;
                
                cout<<"Invalid Copies!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }
        
        void display(){
            cout<<"\n";
            cout<<"---------------- BOOK DETAILS ----------------\n";
            
            cout<<left<<setw(20)<<"Title:"<<p.title<<endl;
            cout<<left<<setw(20)<<"Author:"<<author<<endl;
            cout<<left<<setw(20)<<"Price:"<<p.price<<endl;
            cout<<left<<setw(20)<<"Copies Sold:"<<p.copies<<endl;
            cout<<left<<setw(20)<<"Copies Ordered:"<<orderedCopies<<endl;
            cout<<left<<setw(20)<<"Sales:"<<p.saleCopy()<<endl;
        }
        
        int getOrdered(){
            return orderedCopies;
        }
        
        double getSales(){
            return p.saleCopy();
        }
};

class Magazine{
    public:
        Publication p;
        int orderQty;
        int issue;
        
        void getData(){
            p.getData();
        }
        
        void orderQtyFunc(){
            while(true){
                cout<<"Enter Order Quantity: ";
                cin>>orderQty;
                
                if(!cin.fail() && orderQty>=0)
                break;
                
                cout<<"Invalid Quantity!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }
        
        void currentIssue(){
            while(true){
                cout<<"Enter Current Issue: ";
                cin>>issue;
                
                if(!cin.fail() && issue>0)
                break;
                
                cout<<"Invalid Issue!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }
        
        void receiveIssue(){
            cout<<"Issue Received\n";
        }
        
        void display(){
            cout<<"\n";
            cout<<"--------------- MAGAZINE DETAILS ---------------\n";
            
            cout<<left<<setw(20)<<"Title:"<<p.title<<endl;
            cout<<left<<setw(20)<<"Price:"<<p.price<<endl;
            cout<<left<<setw(20)<<"Copies Sold:"<<p.copies<<endl;
            cout<<left<<setw(20)<<"Order Quantity:"<<orderQty<<endl;
            cout<<left<<setw(20)<<"Issue:"<<issue<<endl;
            cout<<left<<setw(20)<<"Sales:"<<p.saleCopy()<<endl;
        }
        
        double getSales(){
            return p.saleCopy();
        }
};

int main(){
    Book b;
    Magazine m;
    
    cout<<"Enter Book Details\n";
    b.getData();
    b.orderCopies();
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"\nEnter Magazine Details\n";
    m.getData();
    m.orderQtyFunc();
    m.currentIssue();
    m.receiveIssue();
    
    b.display();
    m.display();
    
    double totalSales = b.getSales() + m.getSales();
    
    cout<<"\n---------------------------------------------\n";
    cout<<left<<setw(20)<<"Copies Ordered:"<<b.getOrdered()<<endl;
    cout<<left<<setw(20)<<"Total Sales:"<<totalSales<<endl;
    cout<<"---------------------------------------------\n";

    return 0;
}