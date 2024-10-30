#include <iostream>
#include <stack>
#include <string>

void reverseString(const std::string& input) {
    std::stack<char> charStack;

    // Memasukkan semua karakter ke dalam stack
    for (char ch : input) {
        charStack.push(ch);
    }

    // Mengeluarkan karakter dari stack untuk membentuk string yang terbalik
    std::cout << "Data: ";
    while (!charStack.empty()) {
        std::cout << charStack.top();
        charStack.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::string input;
    std::cout << "Masukkan Kata: ";
    std::getline(std::cin, input);

    // Memeriksa apakah input memiliki minimal 3 kata
    int wordCount = 0;
    for (char ch : input) {
        if (ch == ' ') {
            wordCount++;
        }
    }

    if (wordCount >= 2) { // berarti minimal 3 kata karena ada dua spasi
        std::cout << "Datastack Array:" << std::endl;
        reverseString(input);
    } else {
        std::cout << "Masukkan minimal 3 kata!" << std::endl;
    }

    return 0;
}
