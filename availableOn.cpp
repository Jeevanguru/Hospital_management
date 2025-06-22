#pragma once
#include <iostream>
#include <string>
using namespace std;

class AvailableOn {
    string days;
public:
    AvailableOn() : days("") {}
    AvailableOn(string d) : days(d) {}
    void input() {
        cout << "Enter Available Days (e.g., Mon,Wed,Fri): ";
        getline(cin, days);
    }
    void display() const {
        cout << "Available On: " << days;
    }
    string getDays() const { return days; }
};
// int main() {
//     Available a;
//     a.whenAvailable();
//     a.displayAvailable();
//     return 0;
// }