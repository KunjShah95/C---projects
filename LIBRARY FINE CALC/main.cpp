#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <limits>
using namespace std;

// Helper function to parse dates in format YYYY-MM-DD
int parseDate(const string &date)
{
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

    // Calculate the number of days since year 0
    int days = year * 365 + year / 4 - year / 100 + year / 400; // Leap years
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust for leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        daysInMonth[2] = 29;
    }

    for (int i = 1; i < month; ++i)
    {
        days += daysInMonth[i];
    }

    days += day;
    return days;
}

// Function to add book due dates
void addBookDueDates(map<int, string> &bookDueDates)
{
    int n;
    cout << "Enter the number of books: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int bookID;
        string dueDate;
        cout << "Enter the book ID and due date (YYYY-MM-DD): ";
        cin >> bookID >> dueDate;
        bookDueDates[bookID] = dueDate;
    }
}

// Function to calculate overdue books
void calculateOverdueBooks(const map<int, string> &bookDueDates, vector<pair<int, int>> &overdueBooks)
{
    int m;
    cout << "Enter the number of returned books: ";
    cin >> m;

    for (int i = 0; i < m; ++i)
    {
        int bookID;
        string returnDate;
        cout << "Enter book ID and return date (YYYY-MM-DD): ";
        cin >> bookID >> returnDate;

        if (bookDueDates.find(bookID) != bookDueDates.end())
        {
            int dueDateParsed = parseDate(bookDueDates.at(bookID));
            int returnDateParsed = parseDate(returnDate);

            int overdueDays = returnDateParsed - dueDateParsed;

            if (overdueDays > 0)
            {
                overdueBooks.push_back({bookID, overdueDays});
            }
        }
        else
        {
            cout << "Book ID " << bookID << " not found in the system.\n";
        }
    }

    // Manual sorting of overdue books
    for (size_t i = 0; i < overdueBooks.size(); ++i)
    {
        for (size_t j = i + 1; j < overdueBooks.size(); ++j)
        {
            if (overdueBooks[i].second < overdueBooks[j].second)
            {
                swap(overdueBooks[i], overdueBooks[j]);
            }
        }
    }
}

// Function to display overdue books
void displayOverdueBooks(const vector<pair<int, int>> &overdueBooks, int fineRate)
{
    cout << "\nOverdue Books:\n";
    cout << left << setw(10) << "Book ID" << setw(15) << "Overdue Days" << "Fine ($)" << endl;
    for (const auto &entry : overdueBooks)
    {
        cout << left << setw(10) << entry.first << setw(15) << entry.second << entry.second * fineRate << endl;
    }
}

// Main function
int main()
{
    map<int, string> bookDueDates;       // bookID -> due date
    vector<pair<int, int>> overdueBooks; // {bookID, overdue days}

    int fineRate = 1; // Fine rate: $1 per overdue day
    int choice;

    do
    {
        cout << "\nLibrary Fine Calculator Menu:\n";
        cout << "1. Add Book Due Dates\n";
        cout << "2. Calculate Overdue Books\n";
        cout << "3. Display Overdue Books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        while (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice)
        {
        case 1:
            addBookDueDates(bookDueDates);
            break;
        case 2:
            calculateOverdueBooks(bookDueDates, overdueBooks);
            break;
        case 3:
            displayOverdueBooks(overdueBooks, fineRate);
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the remaining input
        }
    } while (choice != 4);

    return 0;
}
