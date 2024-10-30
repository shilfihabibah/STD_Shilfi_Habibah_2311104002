#ifndef STACK_H
#define STACK_H

#include <string>
#include <vector>

class Stack {
public:
    Stack();
    void push(const std::string& item);
    std::string pop();
    bool isEmpty() const;
    void display() const;

private:
    std::vector<std::string> items;
};

#endif
