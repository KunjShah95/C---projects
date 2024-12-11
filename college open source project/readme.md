# Employee Payroll Management System

This C++ program is a console-based application that allows users to manage employee records, including adding, displaying, and calculating total salaries. It uses object-oriented programming to define an `Employee` class and a `Payroll` class.

## Features

*   Create an employee record with an ID, name, basic salary, and designation
*   Add an employee to the payroll
*   Display all employee records with total salaries calculated
*   Calculate total salary based on basic salary and 10% allowance

## How to Use

1.  Compile the program using a C++ compiler (e.g., GCC)
2.  Run the program
3.  Enter the number of employees to add
4.  Enter the details of each employee
5.  The program will display all employee records with total salaries calculated

## Why Vector is Used

The program uses a `vector` to store the employee records in the `Payroll` class because it provides dynamic memory allocation and efficient insertion and retrieval of elements. This allows the program to easily add and remove employee records without having to worry about memory management or data structure overhead. Additionally, `vector` provides random access to elements, which makes it easier to access and manipulate the employee records.

## Note

*   The program uses `std::setprecision` to set the precision for salary display
*   The program uses `const` to ensure that the `calculateSalary` and `displayDetails` methods do not modify the object state
*   The program uses `cin.ignore()` to ignore the newline character left in the buffer after reading input using `cin`

## License

This program is licensed under the MIT License. See the `LICENSE` file for details.

