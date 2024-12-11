#include <iostream>
#include <vector>
#include <iomanip> // for std::setprecision

using namespace std;

class Employee {
private:
    int employeeID;
    string name;
    double basicSalary;
    string designation;

public:
    // Constructor to initialize employee details
    Employee(int employeeID, string name, double basicSalary, string designation) {
        this->employeeID = employeeID;
        this->name = name;
        this->basicSalary = basicSalary;
        this->designation = designation;
    }

    // Function to input employee details
    void inputDetails() {
        cout << "Enter employee ID: ";
        cin >> employeeID;
        cout << "Enter employee name: ";
        cin.ignore(); // to ignore the newline character left in the buffer
        getline(cin, name);
        cout << "Enter basic salary: ";
        cin >> basicSalary;
        cout << "Enter designation: ";
        cin.ignore(); // to ignore the newline character left in the buffer
        getline(cin, designation);
    }

    // Function to calculate total salary
    double calculateSalary() const { // Add const here
        double allowance = basicSalary * 0.1; // 10% allowance
        return basicSalary + allowance;
    }

    // Function to display employee details
    void displayDetails() const { // Add const here
        cout << fixed << setprecision(2); // Set precision for salary display
        cout << "Employee ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Designation: " << designation << endl;
        cout << "Total Salary: " << calculateSalary() << endl;
    }
};

class Payroll {
private:
    vector<Employee> employees; // List of employees

public:
    // Function to add an employee to the payroll
    void addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }

    // Function to generate and display payroll
    void generatePayroll() {
        cout << "Payroll Details: " << endl;
        for (const Employee& employee : employees) {
            employee.displayDetails();
            cout << "-----------------------------" << endl; // Separator for clarity
        }
    }

    // Function to mark attendance for all employees
    void markAttendanceForAll() { // Placeholder, no actual attendance marking logic
        for (Employee& employee : employees) {
            // employee.markAttendance(); // Add attendance marking logic here if needed
        }
    }
};

int main() {
    Payroll payroll;
    int n;

    cout << "Enter the number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Entering details for employee " << (i + 1) << ":" << endl;

        int employeeID;
        string name;
        double basicSalary;
        string designation;

        // Input employee details
        cout << "Enter employee ID: ";
        cin >> employeeID;
        cout << "Enter employee name: ";
        cin.ignore(); // to ignore the newline character left in the buffer
        getline(cin, name);
        cout << "Enter basic salary: ";
        cin >> basicSalary;
        cout << "Enter designation: ";
        cin.ignore(); // to ignore the newline character left in the buffer
        getline(cin, designation);

        // Create an Employee object and add it to the payroll
        Employee employee(employeeID, name, basicSalary, designation);
        payroll.addEmployee(employee);
    }

    // Mark attendance for all employees
    payroll.markAttendanceForAll();

    // Display the payroll details
    payroll.generatePayroll();

    return 0;
}
