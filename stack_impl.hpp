#include "stack.hpp"

// Default constructor
template <typename T>
Stack<T>::Stack() 
    : m_size(0)
    , m_capacity(0)
    {
        m_ptr = new T[m_capacity];
    }

// Parameterized constructor
template <typename T>
Stack<T>::Stack(size_t size, size_t capacity)
    : m_size(size)
    , m_capacity(capacity)
    , m_ptr(new T[m_capacity])
    {}

// Initializer list constructor
template <typename T>
Stack<T>::Stack(std::initializer_list<T> list)
    : m_size(list.size())
    , m_capacity(m_size)
    {
        m_ptr = new T[m_capacity];

        if (m_size > 0)
        {
            auto it = list.begin();
            for (size_t i = 0; i < m_size; ++i, ++it)
            {
                m_ptr[i] = *it;
            }
        }
    }

// Copy constructor
template <typename T>
Stack<T>::Stack(const Stack& other)
    : m_size(other.m_size)
    , m_capacity(other.m_capacity)
    {
        m_ptr = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i)
        {
            m_ptr[i] = other.m_ptr[i];
        }
    }

// Move constructor
template <typename T>
Stack<T>::Stack(Stack&& other)
    : m_ptr(other.m_ptr)
    , m_size(other.m_size)
    , m_capacity(other.m_capacity)
    {
        other.m_ptr = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }

// Destructor    
template <typename T>
Stack<T>::~Stack() 
{
    if(m_ptr)
    {
        delete [] m_ptr;
    }
}

// Copy assignment operator
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)    
{
    if (this != &other)
    {
        delete[] m_ptr;
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_ptr = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i)
        {
            m_ptr[i] = other.m_ptr[i];
        }
    }
    return *this;
}

// Move assignment operator
template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& other)     
{
    if (this != &other) 
    {
        delete[] m_ptr;
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_ptr = other.m_ptr;
        other.m_capacity = 0;
        other.m_size = 0;
        other.m_ptr = nullptr;
    }
    return *this;
}

// Output stream operator
template<typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& obj) 
{
    for (size_t i = 0; i < obj.size(); ++i)
    {
        os << obj.m_ptr[i];
        if (i < obj.size() - 1)
        {
            os << " ";
        }
    }
    return os;
}

// empty() – Returns whether the stack is empty
template <typename T>
bool Stack<T>::empty()
{
    return m_size == 0;
}

// size() – Returns the size of the stack
template <typename T>
size_t Stack<T>::size() const
{
    return m_size;
}

// top() – Returns a reference to the top most element of the stack
template <typename T>
T Stack<T>::top()
{
    if (!empty())
    {
        return m_ptr[m_size - 1];
    }
    else 
    {
        throw std::out_of_range("Stack is empty");
    }
    
}

// push(g) – Adds the element ‘g’ at the top of the stack
template <typename T>
void Stack<T>::push(T elem)
{
    if (m_size == m_capacity)
    {
        m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        T* tmp = new T[m_capacity];
        if (m_ptr)
        {
            for (size_t i = 0; i < m_size; ++i) 
            {
                tmp[i] = m_ptr[i];
            }
            delete[] m_ptr;
        }
        m_ptr = tmp;
    }
    m_ptr[m_size] = elem;
    ++m_size;
}

// pop() – Deletes the most recent entered element of the stack
template <typename T>
void Stack<T>::pop() 
{
    if (!empty()) 
    {
        --m_size;
    } 
    else 
    {
        throw std::out_of_range("Stack is empty");
    }
}
