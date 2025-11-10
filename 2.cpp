#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;
    int copies;

public:
    Publication() {
        title = "";
        price = 0.0;
        copies = 0;
    }
    
    virtual void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter copies: ";
        cin >> copies;
    }
    
    virtual void putData() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Copies: " << copies << endl;
    }
    
    virtual void saleCopy() {
        if (copies > 0) {
            cout << "Total sale: $" << price * copies << endl;
        } else {
            cout << "No copies available!" << endl;
        }
    }
};

class Book : public Publication {
private:
    string author;

public:
    void getData() {
        Publication::getData();
        cout << "Enter author: ";
        cin.ignore();
        getline(cin, author);
    }
    
    void putData() {
        cout << "\n--- Book Details ---" << endl;
        Publication::putData();
        cout << "Author: " << author << endl;
    }
    
    void saleCopy() {
        cout << "\nBook Sale: ";
        Publication::saleCopy();
    }
    
    void orderCopies(int num) {
        copies += num;
        cout << "Ordered " << num << " copies of " << title << endl;
    }
};

class Magazine : public Publication {
private:
    int orderQty;
    string currentIssue;

public:
    void getData() {
        Publication::getData();
        cout << "Enter order quantity: ";
        cin >> orderQty;
        cout << "Enter current issue: ";
        cin.ignore();
        getline(cin, currentIssue);
    }
    
    void putData() {
        cout << "\n--- Magazine Details ---" << endl;
        Publication::putData();
        cout << "Order Quantity: " << orderQty << endl;
        cout << "Current Issue: " << currentIssue << endl;
    }
    
    void saleCopy() {
        cout << "\nMagazine Sale: ";
        Publication::saleCopy();
    }
    
    void receiveIssue() {
        cout << "Received new issue: " << currentIssue << endl;
    }
    
    void currentIssueInfo() {
        cout << "Current Issue: " << currentIssue << endl;
    }
};

int main() {
    Publication *pub;
    Book book;
    Magazine magazine;
    
    cout << "=== Book Information ===" << endl;
    pub = &book;
    pub->getData();
    pub->putData();
    pub->saleCopy();
    
    cout << "\n=== Magazine Information ===" << endl;
    pub = &magazine;
    pub->getData();
    pub->putData();
    pub->saleCopy();
    
    return 0;
}
