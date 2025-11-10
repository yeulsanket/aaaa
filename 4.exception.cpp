#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int choice;
    bool running = true;
    
    while (running) {
        cout << "\n=== Menu ===" << endl;
        cout << "1. Division" << endl;
        cout << "2. Array Access" << endl;
        cout << "3. Age Check" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int num, den;
                cout << "Enter numerator: ";
                cin >> num;
                cout << "Enter denominator: ";
                cin >> den;
                
                try {
                    if (den == 0) {
                        throw runtime_error("Cannot divide by zero!");
                    }
                    double result = (double)num / den;
                    cout << "Result: " << result << endl;
                }
                catch (runtime_error& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            
            case 2: {
                int arr[5] = {10, 20, 30, 40, 50};
                int index;
                
                cout << "Array: ";
                for (int i = 0; i < 5; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                
                cout << "Enter index (0-4): ";
                cin >> index;
                
                try {
                    if (index < 0 || index >= 5) {
                        throw out_of_range("Index out of bounds!");
                    }
                    cout << "Value: " << arr[index] << endl;
                }
                catch (out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            
            case 3: {
                int age;
                cout << "Enter age: ";
                cin >> age;
                
                try {
                    if (age < 0) {
                        throw invalid_argument("Age cannot be negative!");
                    }
                    if (age > 120) {
                        throw invalid_argument("Age too high!");
                    }
                    cout << "Valid age: " << age << endl;
                    if (age >= 18) {
                        cout << "You are an adult" << endl;
                    } else {
                        cout << "You are a minor" << endl;
                    }
                }
                catch (invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            
            case 4:
                cout << "Goodbye!" << endl;
                running = false;
                break;
            
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
    
    return 0;
}