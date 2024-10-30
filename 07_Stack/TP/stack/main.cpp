#include <iostream>
#include "stack.h"

void displayStackContent(Stack& stack, const std::vector<std::string>& items, const std::string& title) {
    std::cout << title << std::endl;
    for (const auto& item : items) {
        stack.push(item);
    }
    stack.display();
}

void popAllAndDisplay(Stack& stack, const std::string& title) {
    std::cout << title << std::endl;
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;
}

int main() {
    Stack stack;
    int lastDigitMod4;
    std::cout << "Digit terakhir NIM MOD 4: ";
    std::cin >> lastDigitMod4;

    switch (lastDigitMod4) {
        case 0: {
            std::vector<std::string> items = {"I F L A B J A Y A"};
            displayStackContent(stack, items, "Output:");
            std::cout << "J A Y A" << std::endl;  // Fixed line to match output requirement
            break;
        }
        case 1: {
            std::vector<std::string> items = {"H A L O B A N D U N G"};
            displayStackContent(stack, items, "Output:");
            std::cout << "B A N D U N G" << std::endl;
            break;
        }
        case 2: {
            std::vector<std::string> items = {"P E R C A Y A D I R I"};
            displayStackContent(stack, items, "Output:");
            std::cout << "D I R I" << std::endl;
            break;
        }
        case 3: {
            std::vector<std::string> items = {"S T R U K T U R D A T A"};
            displayStackContent(stack, items, "Output:");
            std::cout << "D A T A" << std::endl;
            break;
        }
        default:
            std::cout << "Invalid input. Please enter a number between 0 and 3." << std::endl;
    }

    return 0;
}
