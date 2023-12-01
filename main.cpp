#include "stack.hpp"
#include <iostream>
#include <string>

int main() 
{
    // Testing default constructor
    Stack<int> defaultStack;
    std::cout << "Testing default constructor: ";
    defaultStack.push(10);
    std::cout << "The Stack is: " << defaultStack;

    // Testing parameterized constructor
    Stack<int> paramStack(0, 5);
    std::cout << "\nTesting parameterized constructor: ";
    paramStack.push(10);
    paramStack.push(20);
    std::cout << "The Stack is: " << paramStack;

    // Testing initializer list constructor
    Stack<int> initListStack = {1, 2, 3, 4, 5};
    std::cout << "\nTesting initializer list constructor: " << initListStack;

    // Testing copy constructor
    Stack<int> copyStack = initListStack;
    std::cout << "\nTesting copy constructor: " << copyStack;

    // Testing move constructor
    Stack<int> moveStack = std::move(copyStack);
    std::cout << "\nTesting move constructor: " << moveStack;

    // Testing copy assignment operator
    Stack<int> copyAssignStack;
    copyAssignStack = initListStack;
    std::cout << "\nTesting copy assignment operator: " << copyAssignStack;

    // Testing move assignment operator
    Stack<int> moveAssignStack;
    moveAssignStack = std::move(paramStack);
    std::cout << "\nTesting move assignment operator: " << moveAssignStack;

    // Testing stack operations
    std::cout << "\nIs stack empty? " << (moveAssignStack.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Stack size: " << moveAssignStack.size() << std::endl;
    std::cout << "Top element: " << moveAssignStack.top() << std::endl;
    moveAssignStack.pop();
    std::cout << "Top element after pop: " << moveAssignStack.top() << std::endl;

    return 0;
}
