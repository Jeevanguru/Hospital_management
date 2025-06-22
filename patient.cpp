#include <iostream>
#include <vector>
#include <iomanip>
#include "person.cpp"
#include "disease.cpp"
using namespace std;

class Patient : public Person {
    Disease disease;
public:
    Patient() : Person(), disease() {}
    Patient(int id, string name, int age, string dname, string ddesc)
        : Person(id, name, age), disease(dname, ddesc) {}
    void input() override {
        Person::input();
        disease.input();
    }
    void display() const override {
        Person::display();
        cout << ", "; disease.display();
        cout << endl;
    }
    // Patient management
    static void doPatientRelatedWork();
};

vector<Patient> patients;

void Patient::doPatientRelatedWork() {
    int ch;
    do {
        cout << "\n--- Patient Section ---\n";
        cout << "1. Add Patient\n2. Display Patients\n3. Search by ID\n4. Back\nEnter choice: ";
        cin >> ch;
        cin.ignore();
        if (cin.fail() || ch < 1 || ch > 4) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "[ERROR] Invalid input.\n";
            continue;
        }
        if (ch == 1) {
            Patient p;
            p.input();
            patients.push_back(p);
            cout << "[INFO] Patient added.\n";
        } else if (ch == 2) {
            if (patients.empty()) {
                cout << "[INFO] No patients found.\n";
            } else {
                cout << left << setw(5) << "ID" << setw(15) << "Name" << setw(5) << "Age"
                     << setw(15) << "Disease" << setw(25) << "Description" << endl;
                cout << "-----------------------------------------------------------------\n";
                for (const auto& p : patients) {
                    cout << left << setw(5) << p.getId() << setw(15) << p.name << setw(5) << p.age
                         << setw(15) << p.disease.getName() << setw(25) << p.disease.getDescription() << endl;
                }
            }
        } else if (ch == 3) {
            int id;
            cout << "Enter Patient ID: ";
            cin >> id;
            cin.ignore();
            bool found = false;
            for (const auto& p : patients) {
                if (p.getId() == id) {
                    p.display();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "[INFO] Patient not found.\n";
        }
    } while (ch != 4);
}
// int main() {
//     patient p;
//     p.doPatientRelatedWork();
//     return 0;
// }

