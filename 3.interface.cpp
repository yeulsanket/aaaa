#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    string model;
    int speed;

public:
    Car(string m) {
        model = m;
        speed = 0;
    }
    
    void start() {
        cout << model << " car is starting..." << endl;
    }
    
    void stop() {
        cout << model << " car is stopping..." << endl;
        speed = 0;
    }
    
    void accelerate() {
        speed = speed + 20;
        cout << model << " car is accelerating... Speed: " << speed << " km/h" << endl;
    }
    
    void brake() {
        speed = speed - 15;
        if (speed < 0) speed = 0;
        cout << model << " car is braking... Speed: " << speed << " km/h" << endl;
    }
};

class Bike : public Vehicle {
private:
    string brand;
    int speed;

public:
    Bike(string b) {
        brand = b;
        speed = 0;
    }
    
    void start() {
        cout << brand << " bike is starting..." << endl;
    }
    
    void stop() {
        cout << brand << " bike is stopping..." << endl;
        speed = 0;
    }
    
    void accelerate() {
        speed = speed + 25;
        cout << brand << " bike is accelerating... Speed: " << speed << " km/h" << endl;
    }
    
    void brake() {
        speed = speed - 20;
        if (speed < 0) speed = 0;
        cout << brand << " bike is braking... Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    string carModel, bikeBrand;
    int choice;
    
    cout << "Enter car model: ";
    getline(cin, carModel);
    
    cout << "Enter bike brand: ";
    getline(cin, bikeBrand);
    
    Vehicle *v1 = new Car(carModel);
    Vehicle *v2 = new Bike(bikeBrand);
    
    while (true) {
        cout << "\n=== Vehicle Control Menu ===" << endl;
        cout << "1. Start Car" << endl;
        cout << "2. Accelerate Car" << endl;
        cout << "3. Brake Car" << endl;
        cout << "4. Stop Car" << endl;
        cout << "5. Start Bike" << endl;
        cout << "6. Accelerate Bike" << endl;
        cout << "7. Brake Bike" << endl;
        cout << "8. Stop Bike" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            v1->start();
        } else if (choice == 2) {
            v1->accelerate();
        } else if (choice == 3) {
            v1->brake();
        } else if (choice == 4) {
            v1->stop();
        } else if (choice == 5) {
            v2->start();
        } else if (choice == 6) {
            v2->accelerate();
        } else if (choice == 7) {
            v2->brake();
        } else if (choice == 8) {
            v2->stop();
        } else if (choice == 9) {
            cout << "Exiting program..." << endl;
            break;
        } else {
            cout << "Invalid choice! Try again." << endl;
        }
    }
    
    delete v1;
    delete v2;
    
    return 0;
}