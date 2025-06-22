#include <iostream>
#include "patient.cpp"
#include "doctor.cpp"
using namespace std;

int main() {
    int choice;
    do {
        cout << "\n\n========== HOSPITAL MANAGEMENT SYSTEM ==========\n";
        cout << "1. Patient Section\n";
        cout << "2. Doctor Section\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 3) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "\n[ERROR] Invalid input. Please enter 1, 2, or 3.\n";
            continue;
        }
        switch (choice) {
            case 1:
                Patient::doPatientRelatedWork();
                break;
            case 2:
                Doctor::doDoctorRelatedWork();
                break;
            case 3:
                cout << "\nExiting Hospital Management System.\n";
                break;
        }
    } while (choice != 3);
    return 0;
}


/*
    to run
    first open the folder in integrated terminal or
cd "C:\Users\YourName\Documents\HospitalSystem"
    then compile receptionist.cpp because it includes every other files
g++ receptionist.cpp -o hospital.exe
./hospital.exe

*/