#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Train class
class Train {
public:
    int train_id;
    string train_name;
    string train_type;
    string source;
    string destination;
    string schedule;

    void addTrain() {
        cout << "Enter Train ID: ";
        cin >> train_id;
        cout << "Enter Train Name: ";
        cin.ignore();
        getline(cin, train_name);
        cout << "Enter Train Type: ";
        getline(cin, train_type);
        cout << "Enter Source: ";
        getline(cin, source);
        cout << "Enter Destination: ";
        getline(cin, destination);
        cout << "Enter Schedule (DD/MM/YYYY HH:MM): ";
        getline(cin, schedule);
        saveTrainToFile();
    }

    void editTrain() {
        cout << "Editing Train Info (ID: " << train_id << ")\n";
        cout << "Update Train Name: ";
        getline(cin, train_name);
        cout << "Update Train Type: ";
        getline(cin, train_type);
        cout << "Update Schedule: ";
        getline(cin, schedule);
        saveTrainToFile();
    }

    void deleteTrain() {
        cout << "Train " << train_id << " has been deleted.\n";
        // Logic for deleting from file/database can be added here
    }

    void saveTrainToFile() {
        ofstream file("trains.txt", ios::app);
        file << train_id << " " << train_name << " " << train_type << " "
             << source << " " << destination << " " << schedule << endl;
        file.close();
        cout << "Train details saved to file.\n";
    }

    void getTrainSchedule() {
        cout << "Train Schedule: " << schedule << endl;
    }

    void displayTrains() {
        ifstream file("trains.txt");
        string line;
        cout << "Train Details:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};

// Customer class
class Customer {
public:
    int customer_id;
    string name;
    string address;
    string contact_number;
    string email;
    int loyalty_points;

    void addCustomer() {
        cout << "Enter Customer ID: ";
        cin >> customer_id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Contact Number: ";
        getline(cin, contact_number);
        cout << "Enter Email: ";
        getline(cin, email);
        loyalty_points = 0; // Initialize to zero
        saveCustomerToFile();
    }

    void editCustomer() {
        cout << "Editing Customer Info (ID: " << customer_id << ")\n";
        cout << "Update Name: ";
        getline(cin, name);
        cout << "Update Address: ";
        getline(cin, address);
        cout << "Update Contact Number: ";
        getline(cin, contact_number);
        cout << "Update Email: ";
        getline(cin, email);
        saveCustomerToFile();
    }

    void deleteCustomer() {
        cout << "Customer " << customer_id << " has been deleted.\n";
        // Logic for deleting from file/database can be added here
    }

    void saveCustomerToFile() {
        ofstream file("customers.txt", ios::app);
        file << customer_id << " " << name << " " << address << " "
             << contact_number << " " << email << " " << loyalty_points << endl;
        file.close();
        cout << "Customer details saved to file.\n";
    }

    void viewProfile() {
        cout << "Customer ID: " << customer_id << "\nName: " << name
             << "\nAddress: " << address << "\nContact: " << contact_number
             << "\nEmail: " << email << "\nLoyalty Points: " << loyalty_points << endl;
    }

    void getLoyaltyPoints() {
        cout << "Loyalty Points: " << loyalty_points << endl;
    }

    void redeemLoyaltyPoints() {
        if (loyalty_points >= 100) {
            cout << "Loyalty points redeemed. You get a discount!\n";
            loyalty_points -= 100;
        } else {
            cout << "Not enough points to redeem.\n";
        }
    }
};

// Booking class
class Booking {
public:
    int booking_id;
    int customer_id;
    int train_id;
    string booking_date;
    string booking_time;
    string booking_status;

    void createBooking() {
        cout << "Enter Booking ID: ";
        cin >> booking_id;
        cout << "Enter Customer ID: ";
        cin >> customer_id;
        cout << "Enter Train ID: ";
        cin >> train_id;
        cout << "Enter Booking Date: ";
        cin.ignore();
        getline(cin, booking_date);
        cout << "Enter Booking Time: ";
        getline(cin, booking_time);
        booking_status = "Confirmed";
        saveBookingToFile();
    }

    void editBooking() {
        cout << "Editing Booking (ID: " << booking_id << ")\n";
        cout << "Update Booking Date: ";
        getline(cin, booking_date);
        cout << "Update Booking Time: ";
        getline(cin, booking_time);
        booking_status = "Updated";
        saveBookingToFile();
    }

    void cancelBooking() {
        cout << "Booking " << booking_id << " has been canceled.\n";
        booking_status = "Canceled";
        saveBookingToFile();
    }

    void saveBookingToFile() {
        ofstream file("bookings.txt", ios::app);
        file << booking_id << " " << customer_id << " " << train_id << " "
             << booking_date << " " << booking_time << " " << booking_status << endl;
        file.close();
        cout << "Booking details saved to file.\n";
    }

    void viewBooking() {
        cout << "Booking ID: " << booking_id << "\nCustomer ID: " << customer_id
             << "\nTrain ID: " << train_id << "\nDate: " << booking_date
             << "\nTime: " << booking_time << "\nStatus: " << booking_status << endl;
    }
};

// Ticket class
class Ticket {
public:
    int ticket_id;
    int booking_id;
    int seat_number;
    double price;

    void issueTicket() {
        cout << "Enter Ticket ID: ";
        cin >> ticket_id;
        cout << "Enter Booking ID: ";
        cin >> booking_id;
        cout << "Enter Seat Number: ";
        cin >> seat_number;
        cout << "Enter Ticket Price: ";
        cin >> price;
        printTicket();
    }

    void printTicket() {
        cout << "Ticket ID: " << ticket_id << "\nBooking ID: " << booking_id
             << "\nSeat Number: " << seat_number << "\nPrice: $" << price << endl;
    }
};

// Payment class
class Payment {
public:
    int payment_id;
    int booking_id;
    double amount;

    void processPayment() {
        cout << "Enter Payment ID: ";
        cin >> payment_id;
        cout << "Enter Booking ID: ";
        cin >> booking_id;
        cout << "Enter Amount: ";
        cin >> amount;
        cout << "Payment processed successfully.\n";
    }

    void refundPayment() {
        cout << "Payment ID: " << payment_id << " refunded.\n";
    }
};

// Route class
class Route {
public:
    int route_id;
    int train_id;
    vector<string> stops;

    void addRoute() {
        cout << "Enter Route ID: ";
        cin >> route_id;
        cout << "Enter Train ID: ";
        cin >> train_id;
        int num_stops;
        cout << "Enter number of stops: ";
        cin >> num_stops;
        cin.ignore();
        for (int i = 0; i < num_stops; ++i) {
            string stop;
            cout << "Enter Stop " << i + 1 << ": ";
            getline(cin, stop);
            stops.push_back(stop);
        }
        cout << "Route added successfully.\n";
    }

    void viewRoute() {
        cout << "Route ID: " << route_id << "\nTrain ID: " << train_id << "\nStops: ";
        for (const string& stop : stops) {
            cout << stop << " ";
        }
        cout << endl;
    }
};

// Function to display the menu
void showMenu() {
    cout << "\n--- Train Booking System Menu ---\n";
    cout << "1. Add Train\n";
    cout << "2. Display Trains\n";
    cout << "3. Add Customer\n";
    cout << "4. View Customer Profile\n";
    cout << "5. Create Booking\n";
    cout << "6. Edit Booking\n";
    cout << "7. Cancel Booking\n";
    cout << "8. Issue Ticket\n";
    cout << "9. Process Payment\n";
    cout << "10. Refund Payment\n";
    cout << "11. Add Route\n";
    cout << "12. View Route\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Train train;
    Customer customer;
    Booking booking;
    Ticket ticket;
    Payment payment;
        Route route;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // To handle the newline character after choice input

        switch (choice) {
        case 1:
            train.addTrain();
            break;
        case 2:
            train.displayTrains();
            break;
        case 3:
            customer.addCustomer();
            break;
        case 4:
            customer.viewProfile();
            break;
        case 5:
            booking.createBooking();
            break;
        case 6:
            booking.editBooking();
            break;
        case 7:
            booking.cancelBooking();
            break;
        case 8:
            ticket.issueTicket();
            break;
        case 9:
            payment.processPayment();
            break;
        case 10:
            payment.refundPayment();
            break;
        case 11:
            route.addRoute();
            break;
        case 12:
            route.viewRoute();
            break;
        case 0:
            cout << "Exiting the system.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}