#include <iostream>
#include <string>
using namespace std;

struct AsusLaptop {
    string model;
    string processor;
    string graphics_card;
    int ram;
    int storage;
    double price;
    void display() {
        cout << "Model:" << model << endl;
        cout << "Processor:" << processor << endl;
        cout << "Graphics Card:" << graphics_card << endl;
        cout << "RAM:" << ram << " GB " << endl;
        cout << "Storage: " << storage << " GB " << endl;
        cout << "Price: " << price << " Dollar " << endl;
    }
};

int main() {
    AsusLaptop laptop1;
    laptop1.model = "Asus TUF Gaming F15";
    laptop1.processor = "Intel Core i7";
    laptop1.graphics_card = "GeForce RTX 4070";
    laptop1.ram = 32;
    laptop1.storage = 1000;
    laptop1.price = 566.022;
    laptop1.display();

    return 0;
}
