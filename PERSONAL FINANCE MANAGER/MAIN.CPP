#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
// #include <optional>
#include <limits> // Required for numeric_limits

using namespace std;

class Transaction {
public:
    std::string date;
    std::string description;
    double amount;
    std::string type; // "income" or "expense"

    Transaction(std::string d, std::string desc, double amt, std::string t)
        : date(d), description(desc), amount(amt), type(t) {}
};

class FinanceManager {
private:
    std::vector<Transaction> transactions;
    const std::string filename = "transactions.txt";

    void loadTransactions() {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string date, description, type;
            double amount;
            while (file >> date >> description >> amount >> type) {
                transactions.emplace_back(date, description, amount, type);
            }
            file.close();
        }
    }

    void saveTransactions() {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& transaction : transactions) {
                file << transaction.date << " "
                     << transaction.description << " "
                     << transaction.amount << " "
                     << transaction.type << "\n";
            }
            file.close();
        }
    }

public:
    FinanceManager() {
        loadTransactions();
    }

    ~FinanceManager() {
        saveTransactions();
    }

    void addTransaction() {
        std::string date, description, type;
        double amount;

        std::cout << "Enter date (YYYY-MM-DD): ";
        std::cin >> date;
        std::cout << "Enter description: ";
        std::cin.ignore();
        std::getline(std::cin, description);
        std::cout << "Enter amount: ";
        std::cin >> amount;
        std::cout << "Enter type (income/expense): ";
        std::cin >> type;

        // Validate type
        static const std::unordered_map<std::string, bool> validTypes = {
            {"income", true},
            {"expense", true}
        };

        if (validTypes.find(type) == validTypes.end()) {
            std::cout << "Invalid type! Transaction not added.\n";
            return;
        }

        transactions.emplace_back(date, description, amount, type);
        std::cout << "Transaction added successfully!\n";
    }

    void viewTransactions() {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Date\t\tDescription\t\tAmount\tType\n";
        std::cout << "---------------------------------------------------\n";
        for (const auto& transaction : transactions) {
            std::cout << transaction.date << "\t" 
                      << transaction.description << "\t\t" 
                      << transaction.amount << "\t" 
                      << transaction.type << "\n";
        }
    }

    void deleteTransaction() {
        std::string date;
        std::cout << "Enter the date of the transaction to delete (YYYY-MM-DD): ";
        std::cin >> date;

        auto it = std::remove_if(transactions.begin(), transactions.end(),
            [&date](const Transaction& t) { return t.date == date; });

        if (it != transactions.end()) {
            transactions.erase(it, transactions.end());
            std::cout << "Transaction deleted successfully!\n";
        } else {
            std::cout << "Transaction not found!\n";
        }
    }

    void generateReport() {
        double totalIncome = 0.0;
        double totalExpense = 0.0;

        for (const auto& transaction : transactions) {
            if (transaction.type == "income") {
                totalIncome += transaction.amount;
            } else if (transaction.type == "expense") {
                totalExpense += transaction.amount;
            }
        }

        std::cout << "Total Income: $" << totalIncome << "\n";
        std::cout << "Total Expense: $" << totalExpense << "\n";
        std::cout << "Net Savings: $" << (totalIncome - totalExpense) << "\n";
    }

    void sortTransactions() {
        std::sort(transactions.begin(), transactions.end(), [](const Transaction& a, const Transaction& b) {
            return a.date < b.date; // Sort by date
        });
        std::cout << "Transactions sorted by date.\n";
    }

    void filterTransactions() {
        std::string type;
        std::cout << "Enter type to filter (income/expense): ";
        std::cin >> type;

        auto it = std::remove_if(transactions.begin(), transactions.end(),
            [&type](const Transaction& t) { return t.type != type; });

        if (it != transactions.end()) {
            transactions.erase(it, transactions.end());
            std::cout << "Filtered transactions by type: " << type << "\n";
        } else {
            std::cout << "No transactions found for the specified type!\n";
        }
    }

    void monthlyReport() {
        std::unordered_map<std::string, double> monthlyIncome;
        std::unordered_map<std::string, double> monthlyExpense;

        for (const auto& transaction : transactions) {
            std::string month = transaction.date.substr(0, 7); // Get YYYY-MM
            if (transaction.type == "income") {
                monthlyIncome[month] += transaction.amount;
            } else if (transaction.type == "expense") {
                monthlyExpense[month] += transaction.amount;
            }
        }

        std::cout << "Monthly Report:\n";
        std::cout << "Month\t\tTotal Income\tTotal Expense\n";
        std::cout << "-------------------------------------------\n";
        for (const auto& entry : monthlyIncome) {
            std::cout << entry.first << "\t$" << entry.second << "\t$" 
                      << monthlyExpense[entry.first] << "\n";
        }
    }
};

int main() {
    FinanceManager manager;
    int choice;

    do {
        std::cout << "\nPersonal Finance Manager\n";
        std::cout << "1. Add Transaction\n";
        std::cout << "2. View Transactions\n";
        std::cout << "3. Delete Transaction\n";
        std::cout << "4. Generate Report\n";
        std::cout << "5. Sort Transactions\n";
        std::cout << "6. Filter Transactions\n";
        std::cout << "7. Monthly Report\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                manager.addTransaction();
                break;
            case 2:
                manager.viewTransactions();
                break;
            case 3:
                manager.deleteTransaction();
                break;
            case 4:
                manager.generateReport();
                break;
            case 5:
                manager.sortTransactions();
                break;
            case 6:
                manager.filterTransactions();
                break;
            case 7:
                manager.monthlyReport();
                break;
            case 8:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
