// Include necessary libraries
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes (declaring function before they are defined)
// stock[][3][5] = stock[size][colour][quantity]
void display_menu();
void purchase_order(int stock[][3][5], float prices[]);
void display_availability(int stock[][3][5], float prices[]);
void update_stock(int stock[][3][5], int size_index, int colour_index, int quantity);
float sub_total(float price, int quantity);

int main()
{
    // Declare and initialize t-shirt stock array [size][colour][quantity]
    int stock[5][3][5] = {
        {{30}, {30}, {30}}, // XS
        {{50}, {50}, {50}}, // S
        {{50}, {50}, {50}}, // M
        {{30}, {30}, {30}}, // L
        {{20}, {20}, {20}}  // XL
    };

    // Declare and initialize T-shirt prices array [size]
    float prices[5] = {25.00, 25.00, 30.00, 30.00, 35.00};

    int choice;

    // Main loop
    do
    {
        // Display menu and get user choice
        display_menu();
        cin >> choice;
        cout << endl;

        // Switch statement to handle user choices
        switch (choice)
        {
            case 1:
                display_availability(stock, prices);
                break;
            case 2:
                purchase_order(stock, prices);
                break;
            case 3:
                cout << "Existing program...Thanks for visiting." << "\n" << endl;
                break;
            default:
                cout << "Sorry! Your selection is invalid, please try again." << "\n" << endl;
        }
    } while (choice != 3);
    
    return 0;
}

// Function definitions

// Function to display the main menu
void display_menu()
{
    cout << "______________________________________"  << "\n" << endl;
    cout << "Welcome to the T-Shirt Sales System!" << endl;
    cout << "______________________________________"  << "\n" << endl;
    cout << "1. Display Available T-Shirts" << "\n";
    cout << "2. Purchase T-Shirt" << "\n";
    cout << "3. Exit" << endl;
    cout << "______________________________________"  << "\n" << endl;
    cout << "Enter your choice: ";
}

// Function to display the availability of T-shirts
void display_availability(int stock[][3][5], float prices[])
{
    cout << "Here is the Available T-Shirts: " << endl;
    cout << "__________________________________________________________"  << "\n" << endl;
    cout << setw(6) << "Size" << setw(12) << "Red" << setw(12) << "Blue" << setw(12) << "Black" << setw(12) << "Price" << endl;
    cout << "__________________________________________________________"  << "\n" << endl;

    // Array of strings to represent the size labels
    const string size_label[] = {"XS", "S", "M", "L", "XL"};

    // Loop to display the stock and prices
    // i represents sizes (XS - XL); j represents colour (red, blue, black)
    for (int i = 0; i < 5; ++i)
    {
        cout << setw(6) << size_label[i] << setw(11);

        for (int j = 0; j < 3; ++j)
        {
            cout << stock[i][j][0] << setw(12); 
        }

        cout << "RM " << fixed << setprecision(2) << prices[i] << endl;
    }
    cout << "__________________________________________________________"  << "\n" << endl;
}

// Function to handle the purchase of T-shirts
void purchase_order(int stock[][3][5], float prices[])
{
    int size, colour, quantity;

    cout << "________________________"  << "\n" << endl;
    cout << "Purchasing T-Shirt..." << endl;
    cout << "________________________"  << "\n" << endl;

    // Loop until a valid size is entered
    do
    {
        cout << "Enter the SIZE (1.XS |2.S |3.M |4.L |5.XL): ";
        cin >> size;
        cout << endl;

        if (size < 1 || size > 5)
        {
            cout << "Invalid size! Please enter a valid size." << "\n" << endl;
        }

    } while (size < 1 || size > 5);
    
    // Loop until a valid colour is entered
    do
    {
        cout << "Enter the COLOUR (1.RED |2.BLUE |3.BLACK): ";
        cin >> colour;
        cout << endl;

        if (colour < 1 || colour > 3)
        {
            cout << "Invalid colour! Please enter a valid colour." << "\n" << endl;
        }

    } while (colour < 1 || colour > 3);

    // User input the quantity
    cout << "Enter the QUANTITY (in numbers): ";
    cin >> quantity;
    cout << endl;

    // Represent selected size and colour (by user)
    string a_size, a_colour; 

    switch (size)
    {
        case 1:
            a_size = "XS";
            break;
        case 2:
            a_size = "S";
            break;
        case 3:
            a_size = "M";
            break;
        case 4:
            a_size = "L";
            break;
        case 5:
            a_size = "XL";
            break;
        default:
            a_size = "Invalid";
    }

    switch (colour)
    {
        case 1:
            a_colour = "Red";
            break;
        case 2:
            a_colour = "Blue";
            break;
        case 3:
            a_colour = "Black";
            break;
        default:
            a_colour = "Invalid";
    }

    // Check if there is sufficient stock
    // Use - 1 to convert the user input into a valid array index, as array indices start at 0, not 1
    if (quantity > 0 && stock[size - 1][colour - 1][0] >= quantity)
    {
        // Calculate subtotal
        float subtotal = sub_total(prices[size - 1], quantity);

        // Display purchasing details
        cout << "_____________________________"  << "\n" << endl;
        cout << "Purchasing Details" << endl;
        cout << "_____________________________"  << "\n" << endl;
        cout << "Size: " << a_size << "\n";
        cout << "Colour: " << a_colour << "\n";
        cout << "Quantity: " << quantity << "\n";
        cout << "Price per T-Shirt: RM" << fixed << setprecision(2) << prices[size - 1] << "\n";
        cout << "Subtotal: RM" << fixed << setprecision(2) << subtotal << endl;
        cout << "_____________________________"  << "\n" << endl;

        // Update stock
        // Use - 1 to ensure that the correct location in the 'stock' array is updated
        update_stock(stock, size - 1, colour - 1, quantity);    
    }
    else
    {
        cout << "Sorry! Insufficient stock or invalid quantity." << endl;
    }
}

// Function to update stock
void update_stock(int stock[][3][5], int size, int colour, int quantity)
{
    stock[size][colour][0] -= quantity;
}

// Function to calculate subtotal
float sub_total(float price, int quantity)
{
    return price * quantity;
}