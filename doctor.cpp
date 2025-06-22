#include <iostream>
#include <vector>
#include <iomanip>
#include "person.cpp"
#include "availableOn.cpp"
using namespace std;

class Doctor : public Person {
    string specialization;
    AvailableOn available;
public:
    Doctor() : Person(), specialization(""), available() {}
    Doctor(int id, string name, int age, string spec, string days)
        : Person(id, name, age), specialization(spec), available(days) {}
    void input() override {
        Person::input();
        cout << "Enter Specialization: ";
        getline(cin, specialization);
        available.input();
    }
    void display() const override {
        Person::display();
        cout << ", Specialization: " << specialization << ", ";
        available.display();
        cout << endl;
    }
    string getSpecialization() const { return specialization; }
    // Doctor management
    static void doDoctorRelatedWork();
};

vector<Doctor> doctors;

void Doctor::doDoctorRelatedWork() {
    int ch;
    do {
        cout << "\n--- Doctor Section ---\n";
        cout << "1. Add Doctor\n2. Display Doctors\n3. Search by ID\n4. Back\nEnter choice: ";
        cin >> ch;
        cin.ignore();
        if (cin.fail() || ch < 1 || ch > 4) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "[ERROR] Invalid input.\n";
            continue;
        }
        if (ch == 1) {
            Doctor d;
            d.input();
            doctors.push_back(d);
            cout << "[INFO] Doctor added.\n";
        } else if (ch == 2) {
            if (doctors.empty()) {
                cout << "[INFO] No doctors found.\n";
            } else {
                cout << left << setw(5) << "ID" << setw(15) << "Name" << setw(5) << "Age"
                     << setw(15) << "Specialization" << setw(20) << "Available On" << endl;
                cout << "-------------------------------------------------------------\n";
                for (const auto& d : doctors) {
                    cout << left << setw(5) << d.getId() << setw(15) << d.name << setw(5) << d.age
                         << setw(15) << d.getSpecialization() << setw(20) << d.available.getDays() << endl;
                }
            }
        } else if (ch == 3) {
            int id;
            cout << "Enter Doctor ID: ";
            cin >> id;
            cin.ignore();
            bool found = false;
            for (const auto& d : doctors) {
                if (d.getId() == id) {
                    d.display();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "[INFO] Doctor not found.\n";
        }
    } while (ch != 4);
}
// int main() {
//     doctor d;
//     d.doDoctorRelatedWork();
//     return 0;
// }
