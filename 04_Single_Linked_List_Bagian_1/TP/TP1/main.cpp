#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nim;  // To store each digit
    int digit;

    cout << "Masukkan NIM per digit" << endl;

    // Loop to input each digit
    for (int i = 1; i <= 10; i++) {
        cout << "Digit " << i << " : ";
        cin >> digit;  // Input for each digit
        nim.push_back(digit);  // Store the digit in the vector
    }

    // Displaying the final NIM
    cout << "Isi list : ";
    for (int i = 0; i < nim.size(); i++) {
        cout << nim[i];  // Print each digit
    }

    cout << endl;

    return 0;
}
