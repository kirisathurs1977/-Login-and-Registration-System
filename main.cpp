#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a user
void registerUser() {
    string username, password;
    cout << "Enter a new username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // Check if user already exists
    ifstream read("users.txt");
    string u, p;
    while (read >> u >> p) {
        if (u == username) {
            cout << "Username already exists! Try again.\n";
            return;
        }
    }
    read.close();

    // Store user credentials in file
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
    cout << "Registration successful!\n";
}

// Function to login
bool loginUser() {
    string username, password, u, p;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    while (file >> u >> p) {
        if (u == username && p == password) {
            cout << "Login successful!\n";
            return true;
        }
    }
    cout << "Invalid username or password.\n";
    return false;
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
        break;
        case 2:
            loginUser();
        break;
        default:
            cout << "Invalid choice!\n";
    }

    return 0;
}
