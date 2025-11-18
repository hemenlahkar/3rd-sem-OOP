#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

double my_sqrt(double num) {
    if (num < 0) {
        throw invalid_argument("Cannot compute square root of a negative number!");
    }
    return sqrt(num);
}

int main() {
    double number;
    char choice;
    
    cout << "=== SQUARE ROOT CALCULATOR ===" << endl;
    
    do {
        cout << "\nEnter a number to find its square root: ";
        cin >> number;
        
        try {
            double result = my_sqrt(number);
            cout << "Square root of " << number << " is: " << result << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
            cout << "Please enter a non-negative number." << endl;
        }
        catch (...) {
            cout << "An unexpected error occurred!" << endl;
        }

        cout << "\nDo you want to calculate another square root? (y/n): ";
        cin >> choice;
        
    } while (choice == 'y' || choice == 'Y');
    
    cout << "Thank you for using the square root calculator!" << endl;
    
    return 0;
}
