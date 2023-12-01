#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

template <typename T>
class Stack
{
public:
    Stack();
    Stack(size_t size, size_t capacity);
    Stack(std::initializer_list<T> list);
    Stack(const Stack& other);
    Stack(Stack&& other);
    ~Stack();

    Stack& operator=(const Stack& other);
    Stack& operator=(Stack&& other);
    
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Stack<U>& obj);
public:
    bool empty();
    size_t size() const;
    T top();
    void push(T);
    void pop();

private:
    T* m_ptr;
    size_t m_size;
    size_t m_capacity;
};

#include "stack_impl.hpp"
#endif  // STACK_HPP