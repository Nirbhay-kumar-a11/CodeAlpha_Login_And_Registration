#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

const string USERS_FILE = "users.txt";

// Hash map to store users in memory
unordered_map<string, string> users;

void loadUsers() {
    ifstream file(USERS_FILE);
    string username, password;
    while (file >> username >> password) {
        users[username] = password;
    }
    file.close();
}

bool usernameExists(const string& username) {
    return users.find(username) != users.end();
}

void registerUser() {
    string username, password;

    cout << "Enter a new username: ";
    cin >> username;
    if (usernameExists(username)) {
        cout << "❌ Username already exists. Try another.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    ofstream file(USERS_FILE, ios::app);
    file << username << " " << password << endl;
    file.close();

    users[username] = password; // Update in-memory map

    cout << "✅ Registration successful!\n";
}

void loginUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (usernameExists(username) && users[username] == password) {
        cout << "✅ Login successful. Welcome, " << username << "!\n";
    } else {
        cout << "❌ Invalid username or password.\n";
    }
}

int main() {
    loadUsers();

    int choice;
    while (true) {
        cout << "\n--- Login & Registration System ---\n";
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice.\n"; break;
        }
    }

    return 0;
}