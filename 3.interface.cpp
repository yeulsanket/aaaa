#include <iostream>
using namespace std;


class Vehicle {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
};

class Car : public Vehicle {
private:
    string model;

public:
    Car(string m) {
        model = m;
    }
    
    void start() {
        cout << model << " car is starting..." << endl;
    }
    
    void stop() {
        cout << model << " car is stopping..." << endl;
    }
    
    void accelerate() {
        cout << model << " car is accelerating..." << endl;
    }
    
    void brake() {
        cout << model << " car is applying brakes..." << endl;
    }
};

class Bike : public Vehicle {
private:
    string brand;

public:
    Bike(string b) {
        brand = b;
    }
    
    void start() {
        cout << brand << " bike is starting..." << endl;
    }
    
    void stop() {
        cout << brand << " bike is stopping..." << endl;
    }
    
    void accelerate() {
        cout << brand << " bike is accelerating..." << endl;
    }
    
    void brake() {
        cout << brand << " bike is applying brakes..." << endl;
    }
};

int main() {
    Vehicle *v1 = new Car("Toyota");
    Vehicle *v2 = new Bike("Yamaha");
    
    cout << "=== Car Operations ===" << endl;
    v1->start();
    v1->accelerate();
    v1->brake();
    v1->stop();
    
    cout << "\n=== Bike Operations ===" << endl;
    v2->start();
    v2->accelerate();
    v2->brake();
    v2->stop();
    
    delete v1;
    delete v2;
    
    return 0;
}