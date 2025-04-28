#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int den = 1) {
        numerator = num;
        if (den == 0) {
            cout << "Error: the denominator can not be zero,the value of one was replaced\n";
            denominator = 1;
        } else {
            denominator = den;
        }
        simplify();
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    void display() const {
        cout << numerator;
        if (denominator != 1)
            cout << "/" << denominator;
    }
};

int main() {
    Fraction f1(5, 9);
    Fraction f2(3, 8);

    cout << "first fraction: ";
    f1.display();
    cout << endl;

    cout << "second fraction: ";
    f2.display();
    cout << endl;

    Fraction sum = f1 + f2;
    cout << "Sum: ";
    sum.display();
    cout << endl;

    Fraction diff = f1 - f2;
    cout << "Subtraction: ";
    diff.display();
    cout << endl;

    Fraction product = f1 * f2;
    cout << "Multiplication: ";
    product.display();
    cout << endl;

    return 0;
}
