#include <iostream>
using namespace std;

#define SIZE 6  

int queue[SIZE];
int front = 0, rear = 0, count = 0; // counters

void addPatient(int id) {
    if (count == SIZE) {
        cout << "All stretchers full!\n";
        return;
    }
    queue[rear] = id;
    rear = (rear + 1) % SIZE;
    count++;
    cout << "Patient " << id << " added.\n";
}

void takePatient() {
    if (count == 0) {
        cout << "No patients waiting!\n";
        return;
    }
    cout << "Patient " << queue[front] << " taken for treatment.\n";
    front = (front + 1) % SIZE;
    count--;
}

void showPatients() {
    if (count == 0) {
        cout << "No patients in queue.\n";
        return;
    }
    cout << "Patients waiting: ";
    for (int i = 0; i < count; i++) {
        int idx = (front + i) % SIZE;
        cout << queue[idx] << " ";
    }
    cout << "\n";
}

int main() {
    int choice, id;
    while (1) {
        cout << "\n1. Add Patient\n2. Take Patient\n3. Show Patients\n0. Exit\nChoice: ";
        cin >> choice;
        if (choice == 0) break;
        if (choice == 1) {
            cout << "Enter patient ID: ";
            cin >> id;
            addPatient(id);
        } else if (choice == 2) {
            takePatient();
        } else if (choice == 3) {
            showPatients();
        } else {
            cout << "Invalid!\n";
        }
    }
    return 0;
}