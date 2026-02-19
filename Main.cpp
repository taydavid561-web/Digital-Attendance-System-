
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    string indexNumber;
    string name;
    string programme;

    void registerStudent() {
        cout << "Enter Index Number: ";
        cin >> indexNumber;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Programme: ";
        getline(cin, programme);

        saveToFile();
    }

    void displayStudent() {
        cout << "Index: " << indexNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Programme: " << programme << endl;
        cout << "------------------------" << endl;
    }

    void saveToFile() {
        ofstream file("students.txt", ios::app);
        file << indexNumber << "," << name << "," << programme << endl;
        file.close();
        cout << "Student saved successfully!\n";
    }

    static void viewAllStudents() {
        ifstream file("students.txt");
        string line;

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }
};

class AttendanceSession {
public:
    string courseCode;
    string date;
    string startTime;
    int duration;

    void createSession() {
        cout << "Enter Course Code: ";
        cin >> courseCode;
        cout << "Enter Date (YYYY-MM-DD): ";
        cin >> date;
        cout << "Enter Start Time: ";
        cin >> startTime;
        cout << "Enter Duration (hours): ";
        cin >> duration;

        cout << "Session Created Successfully!\n";
    }

    void markAttendance() {
        ifstream studentFile("students.txt");
        ofstream sessionFile("session_" + courseCode + "_" + date + ".txt");

        string line;
        string status;

        while (getline(studentFile, line)) {
            cout << "Student: " << line << endl;
            cout << "Enter Status (P/A/L): ";
            cin >> status;

            sessionFile << line << "," << status << endl;
        }

        studentFile.close();
        sessionFile.close();

        cout << "Attendance marked successfully!\n";
    }

    void viewReport() {
        ifstream sessionFile("session_" + courseCode + "_" + date + ".txt");
        string line;

        while (getline(sessionFile, line)) {
            cout << line << endl;
        }

        sessionFile.close();
    }
};

int main() {
    Student student;
    AttendanceSession session;
    int choice;

    do {
        cout << "\n--- Digital Attendance System ---\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Create Session\n";
        cout << "4. Mark Attendance\n";
        cout << "5. View Session Report\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                student.registerStudent();
                break;
            case 2:
                Student::viewAllStudents();
                break;
            case 3:
                session.createSession();
                break;
            case 4:
                session.markAttendance();
                break;
            case 5:
                session.viewReport();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
