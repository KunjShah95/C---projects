#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Structure to represent a product
struct Product
{
    string name;
    double price;
    int stock;

    // Display product details
    void display() const
    {
        cout << left << setw(20) << name
             << " | Price: ₹" << setw(8) << price
             << " | Stock: " << stock << endl;
    }
};

// Function to display the product catalog
void displayCatalog(const vector<Product> &products)
{
    if (products.empty())
    {
        cout << "No products available in the store.\n";
        return;
    }
    cout << "\nProduct Catalog:\n";
    cout << string(50, '-') << endl;
    for (const auto &product : products)
    {
        product.display();
    }
    cout << string(50, '-') << endl;
}

// Function to sort products by name
void sortByName(vector<Product> &products)
{
    sort(products.begin(), products.end(), [](const Product &a, const Product &b)
         { return a.name < b.name; });
    cout << "Products sorted by name!\n";
}

// Function to sort products by price
void sortByPrice(vector<Product> &products)
{
    sort(products.begin(), products.end(), [](const Product &a, const Product &b)
         { return a.price < b.price; });
    cout << "Products sorted by price!\n";
}

// Function to search for a product by name
void searchProduct(const vector<Product> &products, const string &name)
{
    auto it = find_if(products.begin(), products.end(), [&name](const Product &p)
                      { return p.name == name; });

    if (it != products.end())
    {
        cout << "\nProduct Found:\n";
        it->display();
    }
    else
    {
        cout << "Product not found.\n";
    }
}

// Function to display the cart
void displayCart(const vector<pair<Product, int>> &cart)
{
    if (cart.empty())
    {
        cout << "Your cart is empty.\n";
        return;
    }
    cout << "\nYour Cart:\n";
    cout << string(50, '-') << endl;
    double total = 0.0;
    for (const auto &item : cart)
    {
        const Product &product = item.first;
        int quantity = item.second;
        cout << left << setw(20) << product.name
             << " | Price: ₹" << setw(8) << product.price
             << " | Quantity: " << quantity << endl;
        total += product.price * quantity;
    }
    cout << string(50, '-') << endl;
    cout << "Total: ₹" << total << endl;
}

// Function to add a product to the cart
void addToCart(vector<Product> &products, vector<pair<Product, int>> &cart, const string &name, int quantity)
{
    auto it = find_if(products.begin(), products.end(), [&name](const Product &p)
                      { return p.name == name; });

    if (it != products.end())
    {
        if (it->stock >= quantity)
        {
            cart.push_back({*it, quantity});
            it->stock -= quantity;
            cout << "Added " << quantity << " of " << name << " to the cart.\n";
        }
        else
        {
            cout << "Insufficient stock available.\n";
        }
    }
    else
    {
        cout << "Product not found.\n";
    }
}

// Function to checkout and calculate the total cost
void checkout(const vector<pair<Product, int>> &cart)
{
    if (cart.empty())
    {
        cout << "Your cart is empty.\n";
        return;
    }

    double total = 0.0;
    for (const auto &item : cart)
    {
        const Product &product = item.first;
        int quantity = item.second;
        total += product.price * quantity;
    }

    cout << "\nCheckout Successful!\n";
    cout << "Total Amount: ₹" << total << endl;
}

int main()
{
    vector<Product> products = {
        {"Laptop", 50000.0, 10},
        {"Smartphone", 15000.0, 20},
        {"Headphones", 2000.0, 50},
        {"Smartwatch", 5000.0, 30},
        {"Tablet", 25000.0, 15}};

    vector<pair<Product, int>> cart;
    int choice;

    do
    {
        cout << "\nOnline Store Menu:\n";
        cout << "1. Display Product Catalog\n";
        cout << "2. Add New Product\n";
        cout << "3. Search for a Product\n";
        cout << "4. Sort Products\n";
        cout << "5. Add Product to Cart\n";
        cout << "6. View Cart\n";
        cout << "7. Checkout\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1: // Display catalog
            displayCatalog(products);
            break;

        case 2:
        { // Add new product
            string name;
            double price;
            int stock;
            cout << "Enter product name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter product price: ";
            cin >> price;
            cout << "Enter product stock: ";
            cin >> stock;
            products.push_back({name, price, stock});
            cout << "Product added successfully.\n";
            break;
        }

        case 3:
        { // Search for a product
            string name;
            cout << "Enter product name to search: ";
            cin.ignore();
            getline(cin, name);
            searchProduct(products, name);
            break;
        }

        case 4:
        { // Sort products
            int sortChoice;
            cout << "\nSort Products By:\n";
            cout << "1. Name\n";
            cout << "2. Price\n";
            cout << "Enter your choice: ";
            cin >> sortChoice;
            if (sortChoice == 1)
            {
                sortByName(products);
            }
            else if (sortChoice == 2)
            {
                sortByPrice(products);
            }
            else
            {
                cout << "Invalid choice.\n";
            }
            break;
        }

        case 5:
        { // Add product to cart
            string name;
            int quantity;
            cout << "Enter product name to add to cart: ";
            cin >> name;
            cout << "Enter quantity: ";
            cin >> quantity;
            addToCart(products, cart, name, quantity);
            break;
        }

        case 6: // View cart
            displayCart(cart);
            break;

        case 7: // Checkout
            checkout(cart);
            cart.clear();
            break;

        case 8: // Exit
            cout << "Thank you for shopping with us!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
