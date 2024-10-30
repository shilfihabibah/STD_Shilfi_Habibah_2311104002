#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& str) {
    std::stack<char> charStack;
    std::string cleanedStr;

    // Menghapus spasi dan mengubah ke huruf kecil untuk memeriksa palindrome
    for (char ch : str) {
        if (isalnum(ch)) { // hanya memasukkan huruf dan angka
            cleanedStr += tolower(ch);
        }
    }

    // Masukkan semua karakter ke dalam stack
    for (char ch : cleanedStr) {
        charStack.push(ch);
    }

    // Memeriksa dengan membandingkan karakter satu per satu dari awal dan akhir
    for (char ch : cleanedStr) {
        if (ch != charStack.top()) {
            return false;
        }
        charStack.pop();
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Masukan Kalimat: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "Kalimat tersebut adalah: Palindrom" << std::endl;
    } else {
        std::cout << "Kalimat tersebut adalah: Bukan Palindrom" << std::endl;
    }

    return 0;
}
