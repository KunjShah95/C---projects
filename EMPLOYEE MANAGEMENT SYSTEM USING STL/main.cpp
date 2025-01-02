#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Structure to hold employee details
struct Employee
{
    string name;
    int id;
    double salary;
};

// Function to display employee details
void displayEmployee(const Employee &emp)
{
    cout << "Name: " << emp.name
         << " | ID: " << emp.id
         << " | Salary: ₹" << fixed << setprecision(2) << emp.salary << endl;
}

// Save employee data to CSV
void saveToCSV(const vector<Employee> &employees)
{
    ofstream file("employees.csv");
    if (!file.is_open())
    {
        cout << "Error creating CSV file!" << endl;
        return;
    }
    file << "Name,ID,Salary\n";
    for (const auto &emp : employees)
    {
        file << emp.name << "," << emp.id << "," << emp.salary << "\n";
    }
    file.close();
    cout << "Data saved to employees.csv" << endl;
}

// Save employee data to PDF (Placeholder)
void saveToPDF(const vector<Employee> &employees)
{
    ofstream file("employees.txt"); // Replace with PDF library
    if (!file.is_open())
    {
        cout << "Error creating PDF file!" << endl;
        return;
    }
    file << setw(10) << "Name"
         << setw(10) << "ID"
         << setw(15) << "Salary\n";
    file << string(35, '-') << "\n";
    for (const auto &emp : employees)
    {
        file << setw(10) << emp.name
             << setw(10) << emp.id
             << setw(15) << fixed << setprecision(2) << emp.salary << "\n";
    }
    file.close();
    cout << "Data saved to employees.txt (Replace with actual PDF generation)." << endl;
}

// Save employee data to Excel (Placeholder)
void saveToExcel(const vector<Employee> &employees)
{
    ofstream file("employees.xls"); // Replace with Excel library
    if (!file.is_open())
    {
        cout << "Error creating Excel file!" << endl;
        return;
    }
    file << "Name\tID\tSalary\n";
    for (const auto &emp : employees)
    {
        file << emp.name << "\t" << emp.id << "\t" << emp.salary << "\n";
    }
    file.close();
    cout << "Data saved to employees.xls (Replace with actual Excel generation)." << endl;
}

// Function to sort employees by name
void sortByName(vector<Employee> &employees)
{
    sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b)
         { return a.name < b.name; });
    cout << "Employees sorted by name!" << endl;
}

// Function to sort employees by ID
void sortByID(vector<Employee> &employees)
{
    sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b)
         { return a.id < b.id; });
    cout << "Employees sorted by ID!" << endl;
}

// Function to sort employees by salary
void sortBySalary(vector<Employee> &employees)
{
    sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b)
         { return a.salary < b.salary; });
    cout << "Employees sorted by salary!" << endl;
}

// Display menu options
void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Display all employees\n";
    cout << "2. Add new employee\n";
    cout << "3. Delete an employee\n";
    cout << "4. Update employee salary\n";
    cout << "5. Search for an employee\n";
    cout << "6. Save data to CSV\n";
    cout << "7. Save data to PDF\n";
    cout << "8. Save data to Excel\n";
    cout << "9. Sort employees\n";
    cout << "10. Exit\n";
}

// Sorting menu
void displaySortingMenu()
{
    cout << "\nSort Employees By:\n";
    cout << "1. Name\n";
    cout << "2. ID\n";
    cout << "3. Salary\n";
    cout << "Enter your choice: ";
}

int main()
{
    // Initial data
    vector<Employee> employees = {
        {"Malav", 1, 55000.0},
        {"Nishiv", 2, 65000.0},
        {"Swet", 3, 70000.0},
        {"Kunj", 4, 80000.0},
        {"Dev", 5, 90000.0}};

    int choice;
    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Display all employees
            for (const auto &emp : employees)
            {
                displayEmployee(emp);
            }
            break;

        case 2:
        { // Add new employee
            string name;
            int id;
            double salary;
            cout << "Enter employee name: ";
            cin >> name;
            cout << "Enter employee ID: ";
            cin >> id;
            cout << "Enter employee salary: ";
            cin >> salary;
            employees.push_back({name, id, salary});
            break;
        }

        case 3:
        { // Delete an employee
            int idToDelete;
            cout << "Enter the ID of the employee to delete: ";
            cin >> idToDelete;
            auto it = remove_if(employees.begin(), employees.end(),
                                [idToDelete](const Employee &emp)
                                { return emp.id == idToDelete; });
            if (it != employees.end())
            {
                employees.erase(it, employees.end());
                cout << "Employee deleted successfully." << endl;
            }
            else
            {
                cout << "Employee not found!" << endl;
            }
            break;
        }

        case 4:
        { // Update employee salary
            string nameToUpdate;
            cout << "Enter the name of the employee to update: ";
            cin >> nameToUpdate;
            auto it = find_if(employees.begin(), employees.end(),
                              [nameToUpdate](const Employee &emp)
                              { return emp.name == nameToUpdate; });
            if (it != employees.end())
            {
                cout << "Enter new salary: ";
                cin >> it->salary;
                cout << "Salary updated successfully." << endl;
            }
            else
            {
                cout << "Employee not found!" << endl;
            }
            break;
        }

        case 5:
        { // Search for an employee
            string nameToSearch;
            cout << "Enter the name of the employee to search: ";
            cin >> nameToSearch;
            auto it = find_if(employees.begin(), employees.end(),
                              [nameToSearch](const Employee &emp)
                              { return emp.name == nameToSearch; });
            if (it != employees.end())
            {
                displayEmployee(*it);
            }
            else
            {
                cout << "Employee not found!" << endl;
            }
            break;
        }

        case 6: // Save data to CSV
            saveToCSV(employees);
            break;

        case 7: // Save data to PDF
            saveToPDF(employees);
            break;

        case 8: // Save data to Excel
            saveToExcel(employees);
            break;

        case 9:
        { // Sort employees
            int sortChoice;
            displaySortingMenu();
            cin >> sortChoice;

            switch (sortChoice)
            {
            case 1:
                sortByName(employees);
                break;
            case 2:
                sortByID(employees);
                break;
            case 3:
                sortBySalary(employees);
                break;
            default:
                cout << "Invalid choice for sorting!" << endl;
            }
            break;
        }

        case 10: // Exit
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again!" << endl;
        }
    } while (choice != 10);

    return 0;
}
