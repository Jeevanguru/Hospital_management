#pragma once
#include <iostream>
#include <string>
using namespace std;

class Disease {
    string name;
    string description;
public:
    Disease() : name(""), description("") {}
    Disease(string n, string d) : name(n), description(d) {}
    void input() {
        cout << "Enter Disease Name: ";
        getline(cin, name);
        cout << "Enter Description: ";
        getline(cin, description);
    }
    void display() const {
        cout << "Disease: " << name << ", Description: " << description;
    }
    string getName() const { return name; }
    string getDescription() const { return description; }
};
// int main() {
//     Disease d;
//     d.getDiseaseDetail();
//     d.showDiseaseList();
//     return 0;
// }