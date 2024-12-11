#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>

using namespace std;

class Hostel {
public:
    string studentName;
    string studentAddress;
    string studentPhone;
    int studentRoom;
    int studentFees;
    int studentRoomType;  // 1: Single, 2: Double, 3: Suite
    int studentBed;       // 1: Upper, 2: Lower
    int studentBedNo;
    string hostelName;
    bool feesPaid;
    string checkInDate;
    string checkOutDate;

    vector<Hostel> students; // Vector to store registered students

    // Constructor to load existing students from file
    Hostel() {
        loadStudentsFromFile();
    }

    // Function to load students from file
    void loadStudentsFromFile() {
        ifstream inFile("students.txt");
        if (!inFile) return; // If file doesn't exist, return

        while (inFile.good()) {
            Hostel student;
            getline(inFile, student.studentName, ',');
            getline(inFile, student.studentAddress, ',');
            getline(inFile, student.studentPhone, ',');
            inFile >> student.studentRoom;
            inFile.ignore(); // Ignore the comma
            inFile >> student.studentFees;
            inFile.ignore(); // Ignore the comma
            inFile >> student.studentRoomType;
            inFile.ignore(); // Ignore the comma
            inFile >> student.studentBedNo;
            inFile.ignore(); // Ignore the comma
            getline(inFile, student.hostelName, ',');
            getline(inFile, student.checkInDate, ',');
            inFile >> student.feesPaid;
            inFile.ignore(); // Ignore the newline
            if (inFile) {
                students.push_back(student);
            }
        }
        inFile.close();
    }

    // Function to register a new student in the hostel
    void registerStudent() {
        cout << "Enter Student Name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, studentName);
        cout << "Enter Student Address: ";
        getline(cin, studentAddress);
        cout << "Enter Student Phone: ";
        getline(cin, studentPhone);
        cout << "Enter Room Number: ";
        cin >> studentRoom;
        cout << "Enter Fees: ";
        cin >> studentFees;

        // Room Type Selection
        cout << "Select Room Type (1: Single, 2: Double, 3: Suite): ";
        cin >> studentRoomType;

        // Bed Type Selection
        cout << "Select Bed Type (1: Upper, 2: Lower): ";
        cin >> studentBed;

        cout << "Enter Bed Number: ";
        cin >> studentBedNo;
        cout << "Enter Hostel Name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, hostelName);
        cout << "Enter Check-In Date (dd-mm-yyyy): ";
        getline(cin, checkInDate);
        feesPaid = false; // Default value for fee payment status

        // Add to student list
        students.push_back(*this);
        saveToFile(*this);
        cout << "Student Registered Successfully!\n";
    }

    // Function to update student information
    void updateStudent(string name) {
        for (Hostel &student : students) {
            if (student.studentName == name) {
                cout << "Updating information for " << name << "...\n";
                cout << "Enter new phone number: ";
                cin >> student.studentPhone;
                                cout << "Enter new address: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, student.studentAddress);
                cout << "Student details updated!\n";
                saveAllToFile();
                return;
            }
        }
        cout << "Student not found!\n";
    }

    // Function to delete a student record
    void deleteStudent(string name) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->studentName == name) {
                students.erase(it);
                saveAllToFile();
                cout << "Student " << name << " deleted!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }

    // Function to display all registered students
    void displayStudents() {
        if (students.empty()) {
            cout << "No students registered yet.\n";
            return;
        }

        cout << "Registered Students:\n";
        for (const Hostel &student : students) {
            cout << "Name: " << student.studentName 
                 << ", Room: " << student.studentRoom 
                 << ", Fees: " << (student.feesPaid ? "Paid" : "Not Paid") 
                 << ", Room Type: " << student.studentRoomType 
                 << ", Bed Type: " << student.studentBed << endl;
        }
    }

    // Function to assign a room (currently a placeholder)
    void assignRoom() {
        cout << "Room Assigned Successfully!\n";
    }

    // Function to pay fees
    void payFees(string name) {
        for (Hostel &student : students) {
            if (student.studentName == name) {
                if (!student.feesPaid) {
                    student.feesPaid = true;
                    saveAllToFile();
                    cout << "Fees paid successfully!\n";
                } else {
                    cout << "Fees already paid.\n";
                }
                return;
            }
        }
        cout << "Student not found!\n";
    }

    // Function to check room availability
    void checkRoomAvailability() {
        cout << "Available Rooms:\n";
        for (int i = 1; i <= 10; ++i) {
            bool isOccupied = false;
            for (const Hostel &student : students) {
                if (student.studentRoom == i) {
                    isOccupied = true;
                    break;
                }
            }
            if (!isOccupied) {
                cout << "Room " << i << " is available.\n";
            }
        }
    }

    // Function to save student details to a file
    void saveToFile(const Hostel &student) {
        ofstream outFile("students.txt", ios::app);
        outFile << student.studentName << "," 
                << student.studentAddress << "," 
                << student.studentPhone << "," 
                << student.studentRoom << ","
                << student.studentFees << "," 
                << student.studentRoomType << "," 
                << student.studentBedNo << "," 
                << student.hostelName << "," 
                << student.checkInDate << "," 
                << student.feesPaid << "\n";
        outFile.close();
    }

    // Function to save all student records to a file
    void saveAllToFile() {
        ofstream outFile("students.txt");
        for (const Hostel &student : students) {
            outFile << student.studentName << "," 
                    << student.studentAddress << "," 
                    << student.studentPhone << "," 
                    << student.studentRoom << ","
                    << student.studentFees << "," 
                    << student.studentRoomType << "," 
                    << student.studentBedNo << "," 
                    << student.hostelName << "," 
                    << student.checkInDate << "," 
                    << student.feesPaid << "\n";
        }
        outFile.close();
    }

    // Function to search for a student by name
    void searchStudent(string name) {
        for (const Hostel &student : students) {
            if (student.studentName == name) {
                cout << "Student Found: " << student.studentName 
                     << ", Room: " << student.studentRoom 
                     << ", Fees: " << (student.feesPaid ? "Paid" : "Not Paid") << endl;
                return;
            }
        }
        cout << "Student not found!\n";
    }

    // Menu function
    void menu() {
        int choice;
        do {
            cout << "\n------Hostel Management System------\n";
            cout << "1. Register a Student\n";
            cout << "2. Update Student Details\n";
            cout << "3. Delete Student\n";
            cout << "4. Display Registered Students\n";
            cout << "5. Pay Fees\n";
                       cout << "6. Check Room Availability\n";
            cout << "7. Assign Room\n";
            cout << "8. Search for a Student\n";
            cout << "9. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                registerStudent();
                break;
            case 2: {
                string name;
                cout << "Enter student name to update: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name);
                updateStudent(name);
                break;
            }
            case 3: {
                string name;
                cout << "Enter student name to delete: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name);
                deleteStudent(name);
                break;
            }
            case 4:
                displayStudents();
                break;
            case 5: {
                string name;
                cout << "Enter student name to pay fees: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name);
                payFees(name);
                break;
            }
            case 6:
                checkRoomAvailability();
                break;
            case 7:
                assignRoom();
                break;
            case 8: {
                string name;
                cout << "Enter student name to search: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name);
                searchStudent(name);
                break;
            }
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 9);
    }
};

int main() {
    Hostel hostel;
    hostel.menu();
    return 0;
}