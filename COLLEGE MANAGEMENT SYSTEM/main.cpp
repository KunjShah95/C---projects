#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime> 
#include <iomanip>

using namespace std;

// Class to represent a college student
class College {
private:
    string name; // Student's name
    int mobile_number; // Student's mobile number
    string email_id; // Student's email ID
    string address; // Student's address
    string city; // Student's city
    string state; // Student's state
    int pincode; // Student's pincode
    string course; // Student's course
    float gpa; // Student's GPA
    time_t date_of_birth; // Store date of birth as a time_t value
    time_t date_of_admission; // Store date of admission as a time_t value

public:
    // Default constructor
    College() {} 

    // Parameterized constructor
    College(string n, int mn, string ei, string a, string c, string s, int p, string co, float g, int year, int month, int day, int admissionYear, int admissionMonth, int admissionDay) {
        name = n;
        mobile_number = mn;
        email_id = ei;
        address = a;
        city = c;
        state = s;
        pincode = p;
        course = co;
        gpa = g;
        setDOB(year, month, day);
        setAdmissionDate(admissionYear, admissionMonth, admissionDay);
    }

    // Getters and setters for private member variables
    string getName() { return name; }
    void setName(string n) { name = n; }

    int getMobileNumber() { return mobile_number; }
    void setMobileNumber(int mn) { mobile_number = mn; }

    string getEmailId() { return email_id; }
    void setEmailId(string ei) { email_id = ei; }

    string getAddress() { return address; }
    void setAddress(string a) { address = a; }

    string getCity() { return city; }
    void setCity(string c) { city = c; }

    string getState() { return state; }
    void setState(string s) { state = s; }

    int getPincode() { return pincode; }
    void setPincode(int p) { pincode = p; }

    string getCourse() { return course; }
    void setCourse(string co) { course = co; }

    float getGPA() { return gpa; }
    void setGPA(float g) { gpa = g; }

    // Date of Birth Methods
    void setDOB(int year, int month, int day) { 
        struct tm tm = {0};
        tm.tm_year = year - 1900; 
        tm.tm_mon = month - 1;   
        tm.tm_mday = day;
        date_of_birth = mktime(&tm); 
    }

    // Calculates the student's age based on their date of birth
    int calculateAge() {
        time_t current_time = time(0);
        int age = (int)difftime(current_time, date_of_birth) / (365.25 * 24 * 60 * 60); // Approximate age in years
        return age;
    }

    // Date of Admission Methods
    void setAdmissionDate(int year, int month, int day) {
        struct tm tm = {0};
        tm.tm_year = year - 1900; 
        tm.tm_mon = month - 1;   
        tm.tm_mday = day;
        date_of_admission = mktime(&tm); 
    }

    // Calculates the student's duration in college based on their admission date
    int calculateDuration() {
        time_t current_time = time(0);
        int duration = (int)difftime(current_time, date_of_admission) / (365.25 * 24 * 60 * 60);
        return duration;
    }


    // Displays the student's information
    void display() {
        cout << "Name: " << name << endl;
        cout << "Mobile Number: " << mobile_number << endl;
        cout << "Email ID: " << email_id << endl;
        cout << "Address: " << address << endl;
        cout << "City: " << city << endl;
        cout << "State: " << state << endl;
        cout << "Pincode: " << pincode << endl;
        cout << "Course: " << course << endl;
        cout << "GPA: " << gpa << endl;
        cout << "Age: " << calculateAge() << " years" << endl;
        cout << "Duration in College: " << calculateDuration() << " years" << endl;
    }

    // Searches for a student based on their name (basic implementation)
    void searchStudent(string n) {
        // This is a basic search implementation for demo purposes
        if (name == n) {
            cout << "Student found!" << endl;
            display();
        } else {
            cout << "Student not found." << endl;
        }
    }

    // Writes the student's information to a file
    void writeToFile(string filename) {
        ofstream file(filename);
        file << "Name: " << name << endl;
        file << "Mobile Number: " << mobile_number << endl;
        file << "Email ID: " << email_id << endl;
        file << "Address: " << address << endl;
        file << "City: " << city << endl;
        file << "State: " << state << endl;
        file << "Pincode: " << pincode << endl;
        file << "Course: " << course << endl;
        file << "GPA: " << gpa << endl;
        file << "Date of Birth (YYYY-MM-DD): " << formatDate(date_of_birth) << endl;
        file << "Date of Admission (YYYY-MM-DD): " << formatDate(date_of_admission) << endl;
        file.close();
    }

    // Reads student information from a file
    void readFromFile(string filename) {
        ifstream file(filename);
        // Add error handling if necessary
        getline(file, name);
        file >> mobile_number;
        getline(file, email_id);
        getline(file, address);
        getline(file, city);
        getline(file, state);
        file >> pincode;
        getline(file, course);
        file >> gpa;

        // Read the date of birth
        string dobStr;
        getline(file, dobStr);
        // Parse the date of birth (assuming it's in YYYY-MM-DD format)
        int year, month, day;
        sscanf(dobStr.c_str(), "Date of Birth (YYYY-MM-DD): %d-%d-%d", &year, &month, &day);
        setDOB(year, month, day); 

        // Read the date of admission
        string admissionDateStr;
        getline(file, admissionDateStr);
        sscanf(admissionDateStr.c_str(), "Date of Admission (YYYY-MM-DD): %d-%d-%d", &year, &month, &day);
        setAdmissionDate(year, month, day);

        file.close();
    }

    // Formats a time_t value into a YYYY-MM-DD string
    string formatDate(time_t timestamp) {
        // Format the date (YYYY-MM-DD)
        struct tm *tm = localtime(&timestamp);
        char buffer[11]; // YYYY-MM-DD
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm);
        return string(buffer);
    }
};

int main() {
    // Create a College object with sample data
    College c1("ABC", 1234567890, "abc@abc", "ABC Street", "ABC City", "ABC State", 123456, "BSc", 8.5, 1995, 10, 25, 2023, 8, 15); // Example DOB: 1995-10-25, Admission: 2023-08-15

    // Display the student's information
    c1.display();

    // Write the student's information to a file
    c1.writeToFile("student_data.txt");

    // Read the student's information from the file
    c1.readFromFile("student_data.txt"); 

    // Display the student's information again (after reading from the file)
    c1.display();

    return 0;
}