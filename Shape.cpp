#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string color;
    string name;

public:
    Shape(string c = "black", string n = "Shape") : color(c), name(n) {}

    void setColor(string c) { color = c; }
    string getColor() const { return color; }

    void setName(string n) { name = n; }
    string getName() const { return name; }

    virtual double calculateArea() const { return 0.0; }
    virtual double calculatePerimeter() const { return 0.0; }

    virtual void printDetails() const {
        cout << "Name: " << name << "\nColor: " << color << endl;
    }

    virtual void draw() const {
        cout << "Drawing a " << color << " " << name << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w = 1.0, double h = 1.0, string c = "blue")
        : Shape(c, "Rectangle"), width(w), height(h) {}

    void setDimensions(double w, double h) { width = w; height = h; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }

    void draw() const override {
        cout << "\nRectangle Shape:\n";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << "* ";
            }
            cout << endl;
        }
    }

    void printDetails() const override {
        Shape::printDetails();
        cout << "Width: " << width << "\nHeight: " << height
             << "\nArea: " << calculateArea()
             << "\nPerimeter: " << calculatePerimeter() << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r = 1.0, string c = "red")
        : Shape(c, "Circle"), radius(r) {}

    void setRadius(double r) { radius = r; }
    double getRadius() const { return radius; }

    double calculateArea() const override {
        return 3.14 * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * 3.14 * radius;
    }

    void draw() const override {
        cout << "\n   **\n *     *\n       *\n *     *\n   ***\n";
        cout << "Circle with radius " << radius << endl;
    }

    void printDetails() const override {
        Shape::printDetails();
        cout << "Radius: " << radius << "\nArea: " << calculateArea()
             << "\nCircumference: " << calculatePerimeter() << endl;
    }
};

void displayMenu() {
    cout << "\n===== Shape Management System =====\n";
    cout << "1. Create Rectangle\n";
    cout << "2. Create Circle\n";
    cout << "3. Show Shape Details\n";
    cout << "4. Draw Shape\n";
    cout << "5. Calculate Area\n";
    cout << "6. Calculate Perimeter\n";
    cout << "7. Change Color\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Shape* currentShape = nullptr;
    int choice;
    double w, h, r;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "Enter width and height: ";
                cin >> w >> h;
                currentShape = new Rectangle(w, h);
                cout << "Rectangle created!\n";
                break;
            }
            case 2: {
                cout << "Enter radius: ";
                cin >> r;
                currentShape = new Circle(r);
                cout << "Circle created!\n";
                break;
            }
            case 3: {
                if (currentShape) {
                    currentShape->printDetails();
                } else {
                    cout << "No shape created yet!\n";
                }
                break;
            }
            case 4: {
                if (currentShape) {
                    currentShape->draw();
                } else {
                    cout << "No shape created yet!\n";
                }
                break;
            }
            case 5: {
                if (currentShape) {
                    cout << "Area: " << currentShape->calculateArea() << endl;
                } else {
                    cout << "No shape created yet!\n";
                }
                break;
            }
            case 6: {
                if (currentShape) {
                    cout << "Perimeter: " << currentShape->calculatePerimeter() << endl;
                } else {
                    cout << "No shape created yet!\n";
                }
                break;
            }
            case 7: {
                if (currentShape) {
                    string newColor;
                    cout << "Enter new color: ";
                    getline(cin, newColor);
                    currentShape->setColor(newColor);
                    cout << "Color changed to " << newColor << endl;
                } else {
                    cout << "No shape created yet!\n";
                }
                break;
            }
            case 0: {
                cout << "Exiting program...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (choice != 0);

    delete currentShape;
    return 0;
}
