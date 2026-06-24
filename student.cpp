#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

Student s[100];
int count = 0;

void addStudent() {
    cout << "Enter Roll No: ";
    cin >> s[count].roll;
    cout << "Enter Name: ";
    cin >> s[count].name;
    cout << "Enter Marks: ";
    cin >> s[count].marks;
    count++;
    cout << "Student Added Successfully!\n";
}

void displayStudents() {
    for(int i = 0; i < count; i++) {
        cout << "\nRoll No: " << s[i].roll;
        cout << "\nName: " << s[i].name;
        cout << "\nMarks: " << s[i].marks << endl;
    }
}

void searchStudent() {
    int roll;
    cout << "Enter Roll No to search: ";
    cin >> roll;
    for(int i = 0; i < count; i++) {
        if(s[i].roll == roll) {
            cout << "Found!\n";
            cout << "Name: " << s[i].name << "\nMarks: " << s[i].marks;
            return;
        }
    }
    cout << "Student Not Found!\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter Roll No to delete: ";
    cin >> roll;
    for(int i = 0; i < count; i++) {
        if(s[i].roll == roll) {
            for(int j = i; j < count - 1; j++) {
                s[j] = s[j+1];
            }
            count--;
            cout << "Deleted Successfully!\n";
            return;
        }
    }
    cout << "Student Not Found!\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. Display\n3. Search\n4. Delete\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice!\n";
        }
    } while(choice != 5);

    return 0;
}