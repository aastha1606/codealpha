#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a user
void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // Writing the username and password to a file
    ofstream file;
    file.open("database.txt", ios::app);  // Open file in append mode
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful!\n";
    } else {
        cout << "Error: Unable to open the file.\n";
    }
}

// Function to login a user
bool loginUser() {
    string username, password, u, p;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Reading from the file to verify credentials
    ifstream file("database.txt");
    if (file.is_open()) {
        while (file >> u >> p) {  // Reading username and password from file
            if (u == username && p == password) {
                file.close();
                return true;  // Credentials matched
            }
        }
        file.close();
        return false;  // No matching credentials
    } else {
        cout << "Error: Unable to open the file.\n";
        return false;
    }
}

// Main menu function
void menu() {
    int choice;
    cout << "1. Register\n2. Login\n3. Exit\n";
    cout << "Choose an option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser()) {
                cout << "Login successful!\n";
            } else {
                cout << "Login failed. Incorrect username or password.\n";
            }
            break;
        case 3:
            cout << "Exiting the program.\n";
            exit(0);
        default:
            cout << "Invalid choice. Try again.\n";
    }
}

int main() {
    while (true) {
        menu();  // Display the menu in a loop
    }
    return 0;
}