#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createPasswordFile() {
    ofstream passwordFile("Pass.txt");
    if (passwordFile.is_open()) {
        passwordFile << "password123\n";
        passwordFile << "helloWorld\n";
        passwordFile << "letmein\n";
        passwordFile << "admin\n";
        passwordFile << "qwerty\n";
        passwordFile.close();
    } else {
        cout << "Unable to create file." << endl;
    }
}
bool checkPassword(const string& inputPassword) {
    ifstream passwordFile("Pass.txt");
    string line;

    while (getline(passwordFile, line)) {
        if (line == inputPassword) {
            return true;
        }
    }

    return false;
}

int main() {
    createPasswordFile();

    string userInput;
    int attempts = 0;
    const int maxAttempts = 5;

    while (attempts < maxAttempts) {
        cout << "Enter your password: ";
        cin >> userInput;

        if (checkPassword(userInput)) {
            cout << "Login successful" << endl;
            return 0;
        } else {
            cout << "The password is incorrect. Try again." << endl;
            attempts++;
        }
    }

    cout << "App lock" << endl;
    return 0;
}
