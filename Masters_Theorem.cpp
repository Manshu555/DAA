#include <bits/stdc++.h>
using namespace std;

// Function to calculate log base b of a
double logBase(double a, double b) {
    if (a <= 0 || b <= 0 || b == 1) {
        cerr << "Invalid input: a and b must be positive, and b cannot be 1." << endl;
        return NAN; // Return NaN to indicate an error
    }
    return log(a) / log(b);
}

// Function to apply the Master Theorem and print the result
void applyMasterTheorem(double a, double b, double c, double k, int caseType) {
    // Check if Master Theorem can be applied
    if (a < 1) {
        cout << "The Master Theorem cannot be applied when a < 1." << endl;
        return;
    }
    if (c < 0 || k < 0) {
        cout << "The Master Theorem assumes f(n) is a polynomial. If c < 0 or k < 0, it may not apply." << endl;
        return;
    }

    double log_b_a = logBase(a, b);
    if (isnan(log_b_a)) {
        return; // Error already printed in logBase function
    }

    switch (caseType) {
        case 1:
            // Case 1: f(n) = O(n^log_b(a) - ε)
            cout << "Case 1: T(n) = O(n^" << fixed << setprecision(2) << log_b_a << ")" << endl;
            break;
        case 2:
            // Case 2: f(n) = Θ(n^log_b(a) * log^k(n))
            cout << "Case 2: T(n) = Θ(n^" << fixed << setprecision(2) << log_b_a;
            if (k > 0) {
                cout << " * log^" << k << "(n)";
            }
            cout << ")" << endl;
            break;
        case 3:
            // Case 3: f(n) = Ω(n^log_b(a) + ε) and regularity condition holds
            cout << "Case 3: T(n) =  Ω(n^" << fixed << setprecision(2) << log_b_a << ")" << endl;
            break;
        case 4:
            // Case 4: The Master Theorem cannot be applied
            cout << "Case 4: The Master Theorem cannot be applied to this recurrence relation." << endl;
            break;
        default:
            cout << "Invalid Case Type Specified!" << endl;
            break;
    }
}

int main() {
    double a, b, c, k;
    int type;

    // Prompt the user for input
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Enter the value of c: ";
    cin >> c;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Enter the case type (1, 2, 3, or 4): ";
    cin >> type;

    // Apply the Master Theorem
    applyMasterTheorem(a, b, c, k, type);

    return 0;
}