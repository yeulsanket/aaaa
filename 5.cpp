#include <iostream>
#include <string>
using namespace std;

class Employee{
protected:
    string name;
    string id;
    string email;
    string phone;
    double basicPay;

public:
    Employee(){
        name = "";
        id = "";
        email = "";
        phone = "";
        basicPay = 0;
}    
Employee(string n, string i, string e, string p, double pay) {
        name = n;
        id = i;
        email = e;
        phone = p;
        basicPay = pay;
}
    void displayDetails() {
        cout << "\nEmployee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
    }
    virtual void generatePaySlip() {
        double DA = basicPay * 0.50;
        double HRA = basicPay * 0.20;
        double PF = basicPay * 0.12;
        
        double grossSalary = basicPay + DA + HRA;
        double netSalary = grossSalary - PF;
        
        cout << "\n===== PAY SLIP =====" << endl;
        displayDetails();
        cout << "\nBasic Pay: " << basicPay << endl;
        cout << "DA (50%): " << DA << endl;
        cout << "HRA (20%): " << HRA << endl;
        cout << "-------------------" << endl;
        cout << "Gross Salary: " << grossSalary << endl;
        cout << "PF (12%): " << PF << endl;
        cout << "-------------------" << endl;
        cout << "Net Salary: " << netSalary << endl;
        cout << "===================\n" << endl;
    }

    string getName() {
        return name;
    }
};
class Programmer : public Employee {
public:
    Programmer() : Employee() {}
    Programmer(string n, string i, string e, string p, double pay)
        : Employee(n, i, e, p, pay) {}
    void generatePaySlip() {
        cout << "\n*** PROGRAMMER ***";
        Employee::generatePaySlip();
    }
};
class TeamLead : public Employee {
public:
    TeamLead() : Employee() {}
    TeamLead(string n, string i, string e, string p, double pay)
        : Employee(n, i, e, p, pay) {}
    void generatePaySlip() {
        cout << "\n*** TEAM LEAD ***";
        Employee::generatePaySlip();
    }
};

class Manager : public Employee {
public:
    Manager() : Employee() {}
    Manager(string n, string i, string e, string p, double pay)
        : Employee(n, i, e, p, pay) {}
    void generatePaySlip() {
        cout << "\n*** MANAGER ***";
        Employee::generatePaySlip();
    }
};
int main() {
    Employee* employees[100];
    int empCount = 0;
    int choice;
    string name, id, email, phone;
    double basicPay;
    while (true) {
        cout << "\n===== EMPLOYEE PAYROLL SYSTEM =====" << endl;
        cout << "1. Add Programmer" << endl;
        cout << "2. Add Team Lead" << endl;
        cout << "3. Add Manager" << endl;
        cout << "4. View All Employees" << endl;
        cout << "5. Generate Pay Slip for an Employee" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                cout << "\nEnter Programmer Details:" << endl;
                cout << "Name: ";
                getline(cin, name);
                cout << "ID: ";
                getline(cin, id);
                cout << "Email: ";
                getline(cin, email);
                cout << "Phone: ";
                getline(cin, phone);
                cout << "Basic Pay: ";
                cin >> basicPay;
                employees[empCount] = new Programmer(name, id, email, phone, basicPay);
                empCount++;
                cout << "\nProgrammer added successfully!" << endl;
                break;
            }
            case 2: {
                cout << "\nEnter Team Lead Details:" << endl;
                cout << "Name: ";
                getline(cin, name);
                cout << "ID: ";
                getline(cin, id);
                cout << "Email: ";
                getline(cin, email);
                cout << "Phone: ";
                getline(cin, phone);
                cout << "Basic Pay: ";
                cin >> basicPay;
                
                employees[empCount] = new TeamLead(name, id, email, phone, basicPay);
                empCount++;
                cout << "\nTeam Lead added successfully!" << endl;
                break;
            }
            case 3: {
                cout << "\nEnter Manager Details:" << endl;
                cout << "Name: ";
                getline(cin, name);
                cout << "ID: ";
                getline(cin, id);
                cout << "Email: ";
                getline(cin, email);
                cout << "Phone: ";
                getline(cin, phone);
                cout << "Basic Pay: ";
                cin >> basicPay;
                employees[empCount] = new Manager(name, id, email, phone, basicPay);
                empCount++;
                cout << "\nManager added successfully!" << endl;
                break;
            }
            case 4: {
                if (empCount == 0) {
                    cout << "\nNo employees in the system!" << endl;
                } else {
                    cout << "\n===== ALL EMPLOYEES =====" << endl;
                    for (int i = 0; i < empCount; i++) {
                        cout << (i + 1) << ". ";
                        employees[i]->displayDetails();
                        cout << endl;
                    }
                }
                break;
            }
            case 5: {
                if (empCount == 0) {
                    cout << "\nNo employees in the system!" << endl;
                } else {
                    cout << "\n===== SELECT EMPLOYEE =====" << endl;
                    for (int i = 0; i < empCount; i++) {
                        cout << (i + 1) << ". " << employees[i]->getName() << endl;
                    }
                    int empChoice;
                    cout << "Enter employee number: ";
                    cin >> empChoice;
                    
                    if (empChoice > 0 && empChoice <= empCount) {
                        employees[empChoice - 1]->generatePaySlip();
                    } else {
                        cout << "\nInvalid employee number!" << endl;
                    }
                }
                break;
            }
            case 6:
                cout << "\nExiting system. Goodbye!" << endl;
                for (int i = 0; i < empCount; i++) {
                    delete employees[i];
                }
                return 0;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    }
    return 0;
}