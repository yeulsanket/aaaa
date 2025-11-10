#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:

    Complex() {
        real = 0;
        imaginary = 0;
    }
    
   
    Complex(double r, double i) {
        real = r;
        imaginary = i;
    }
    
   
    Complex add(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.imaginary = imaginary + c.imaginary;
        return result;
    }
    
    
    Complex subtract(Complex c) {
        Complex result;
        result.real = real - c.real;
        result.imaginary = imaginary - c.imaginary;
        return result;
    }
    
    
    Complex multiply(Complex c) {
        Complex result;
        result.real = real * c.real - imaginary * c.imaginary;
        result.imaginary = real * c.imaginary + imaginary * c.real;
        return result;
    }
    
    
    Complex divide(Complex c) {
        Complex result;
        double denominator = c.real * c.real + c.imaginary * c.imaginary;
        result.real = (real * c.real + imaginary * c.imaginary) / denominator;
        result.imaginary = (imaginary * c.real - real * c.imaginary) / denominator;
        return result;
    }
    
   
    void display() {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main() {
    Complex c1(3, 2);
    Complex c2(1, 7);
    
    cout << "Complex Number 1: ";
    c1.display();
    cout << "Complex Number 2: ";
    c2.display();
    
    Complex sum = c1.add(c2);
    Complex diff = c1.subtract(c2);
    Complex prod = c1.multiply(c2);
    Complex quot = c1.divide(c2);
    
    cout << "\nAddition: ";
    sum.display();
    cout << "Subtraction: ";
    diff.display();
    cout << "Multiplication: ";
    prod.display();
    cout << "Division: ";
    quot.display();
    
    return 0;
}
