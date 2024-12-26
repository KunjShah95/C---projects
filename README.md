# C++ Projects Repository

Welcome to the C++ Projects repository! This repository contains a collection of projects developed in C++. Each project is designed to demonstrate various programming concepts and techniques in C++. Below you'll find details on each project, including features, installation instructions, usage examples, and more.

![C++](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
![License](https://img.shields.io/github/license/KunjShah95/CPP-projects)

## Projects Overview

### 1. Employee Record Management System

A C++ program to manage employee records, including adding, displaying, searching, updating, and deleting employee data.

**Features:**
- Add employee data
- Display all employee data
- Search for employee data by ID
- Update employee data
- Delete employee data

**Installation:**
1. Clone the repository: `git clone https://github.com/KunjShah95/CPP-projects.git`
2. Navigate to the project directory: `cd employee-record-management-system`
3. Compile the program: `g++ main.cpp -o employee_record_management_system`
4. Run the program: `./employee_record_management_system`

**Usage:**
Run the program and select an option from the menu:
- 1: Enter Employee Data
- 2: Show Employee Data
- 3: Search Employee Data
- 4: Update Employee Data
- 5: Delete Employee Data
- 6: Exit

### 2. ATM Banking System

A C++ program for managing ATM banking operations, including deposits, withdrawals, and transfers.

**Code Sample:**
```c++
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

// Define constants and macros
#define DASHES 50
#define TX 10
// More code...
```
[View more details](https://github.com/KunjShah95/CPP-projects/blob/main/ATM/BANKING.CPP)

### 3. Elevator Control System

A C++ program to simulate an elevator control system.

**Code Sample:**
```c++
#include <iostream>
#include <bitset>

#define MAX_FLOORS 10

// Function to shift the floor unit based on direction
void shiftFloorUnit(int &floorUnit, bool goingUp) {
    if (goingUp) {
        floorUnit <<= 1;
    } else {
        floorUnit >>= 1;
    }
}
// More code...
```
[View more details](https://github.com/KunjShah95/CPP-projects/blob/main/ELEVATOR/MAIN.CPP)

### 4. College Management System

A C++ program to manage college student records.

**Code Sample:**
```c++
// Class to represent a college student
class College {
private:
    string name;
    int mobile_number;
    string email_id;
    string address;
    string city;
    string state;
    int pincode;
    string course;
    float gpa;
    time_t date_of_birth;
    time_t date_of_admission;

public:
    // Default constructor
    College() {}
    // More code...
```
[View more details](https://github.com/KunjShah95/CPP-projects/blob/main/COLLEGE%20MANAGEMENT%20SYSTEM/main.cpp)

### 5. Personal Finance Manager

A C++ program to manage personal finances, including tracking income and expenses.

**Code Sample:**
```c++
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Transaction {
public:
    std::string date;
    std::string description;
    double amount;
    std::string type;

    Transaction(std::string d, std::string desc, double amt, std::string t)
        : date(d), description(desc), amount(amt), type(t) {}
};
// More code...
```
[View more details](https://github.com/KunjShah95/CPP-projects/blob/main/PERSONAL%20FINANCE%20MANAGER/MAIN.CPP)

### 6. Hostel Management System

A C++ program to manage hostel records, including student registrations and room allocations.

**Code Sample:**
```c++
int studentRoom;
int studentFees;
int studentRoomType;
int studentBed;
int studentBedNo;
string hostelName;
bool feesPaid;
string checkInDate;
string checkOutDate;

// Constructor to load existing students from file
Hostel() {
    loadStudentsFromFile();
}
// More code...
```
[View more details](https://github.com/KunjShah95/CPP-projects/blob/main/HOSTEL%20MANAGEMENT%20SYSTEM/main.cpp)

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please fork the repository and submit a pull request.

## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

---

You can view more details and projects in the repository by following this [link](https://github.com/KunjShah95/CPP-projects).
