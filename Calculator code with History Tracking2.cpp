// Calculator code with History Tracking.cpp 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Calculation {
    string expression;
    double result;
};

int main() {
    char op;
    double num1, num2;
    vector<Calculation> history;

    do {
        // Input
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        cout << "Enter second number: ";
        cin >> num2;

        // Perform calculation
        double result;
        switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            }
            else {
                cout << "Error: Division by zero is undefined.\n";
                continue;  // Skip adding to history in case of division by zero
            }
            break;
        default:
            cout << "Invalid operator!\n";
            continue;  // Skip adding to history in case of an invalid operator
        }

        // Display result
        cout << "Result: " << result << endl;

        // Add to history
        history.push_back({ to_string(num1) + " " + op + " " + to_string(num2), result });

        // Ask if the user wants to perform another calculation
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> op;

    } while (op == 'y' || op == 'Y');

    // Display calculation history
    cout << "\nCalculation History:\n";
    for (const auto& entry : history) {
        cout << entry.expression << " = " << entry.result << endl;
    }

    return 0;
}

