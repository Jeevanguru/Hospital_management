#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
    int age;
public:
    Person() : id(0), name(""), age(0) {}
    Person(int id, string name, int age) : id(id), name(name), age(age) {}
    virtual void input() {
        cout << "Enter ID: ";
        while (!(cin >> id)) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "[ERROR] Invalid ID. Enter again: ";
        }
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        while (!(cin >> age) || age <= 0) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "[ERROR] Invalid Age. Enter again: ";
        }
        cin.ignore();
    }
    virtual void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age;
    }
    int getId() const { return id; }
};
// // Main function to test Person class
// int main() {
//     Person p;
//     p.getPersonData();
//     cout << "\n--- Person Details ---\n";
//     p.showPersonData();
//     return 0;
// }