#ifndef ITERABLE_H
#define ITERABLE_H

#include <iostream>
#include "GTUIterator.h"
#include "GTUIteratorConst.h"

using namespace std;
namespace Aysegul_GTU{

template <typename T>
class Iterable 
{
public:

    //best practice
    Iterable();
    Iterable(const Iterable& other);
    Iterable& operator=(const Iterable& other);

    // move constructor
    Iterable(Iterable&& other);
    Iterable& operator=(Iterable&& other);

    // destructor
    virtual ~Iterable() = 0;



    // expected functions
    virtual GTUIterator<T> begin() const = 0;
    virtual GTUIterator<T> end() const = 0;
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual void erase(GTUIterator<T> it) = 0;
    virtual void clear() = 0;
    virtual const GTUIteratorConst<T> cbegin() const = 0;
    virtual const GTUIteratorConst<T> cend() const = 0;


// I use protected because all derived classes will use them
protected:
    shared_ptr<Node<T>> head;
    shared_ptr<Node<T>> tail;
    int _size;
};

// default constructor

template <typename T>
Iterable<T>::Iterable()
{

    head = nullptr;
    tail = nullptr;
    _size = 0;
}

template <typename T>
Iterable<T>::Iterable(const Iterable& other)
{
    head = other.head;
    tail = other.tail;
    _size = other._size;

}

template <typename T>
Iterable<T>& Iterable<T>::operator=(const Iterable& other)
{
    if(this != &other)
    {
        head = other.head;
        tail = other.tail;
        _size = other._size;
    }
    return *this;
}

// move constructor
template <typename T>
Iterable<T>::Iterable(Iterable&& other)
{
    head = other.head;
    tail = other.tail;
    _size = other._size;
    other.head = nullptr;
    other.tail = nullptr;
    other._size = 0;
}

template <typename T>
Iterable<T>& Iterable<T>::operator=(Iterable&& other)
{
    if(this != &other)
    {
        head = other.head;
        tail = other.tail;
        _size = other._size;
        other.head = nullptr;
        other.tail = nullptr;
        other._size = 0;
    }
    return *this;
}


// destructor
template <typename T>
Iterable<T>::~Iterable()
{
    head = nullptr;
    tail = nullptr;
    _size = 0;
}

template <typename T>
GTUIterator<T> Iterable<T>::begin() const
{
    if (head == nullptr)
    {
        throw "Empty Iterable";
    }

    return GTUIterator<T>(head);
}

template <typename T>
GTUIterator<T> Iterable<T>::end() const
{   
    if (head == nullptr)
    {
        throw "Empty Iterable";
    }
    
    
    return GTUIterator<T>(tail);
}

template <typename T>
const GTUIteratorConst<T> Iterable<T>::cbegin() const
{
    if (head == nullptr)
    {
        throw "Empty Iterable";
    }

    return GTUIteratorConst<T>(head);
}

template <typename T>
const GTUIteratorConst<T> Iterable<T>::cend() const
{
    if (head == nullptr)
    {
        throw "Empty Iterable";
    }
    return GTUIteratorConst<T>(tail);
}

template <typename T>
int Iterable<T>::size() const
{
    return this->_size;
}

template <typename T>
bool Iterable<T>::empty() const
{
    return this->_size == 0;
}

template <typename T>
void Iterable<T>::clear()
{
    head = nullptr;
    tail = nullptr;
    _size = 0;
}

template <typename T>
void Iterable<T>::erase(GTUIterator<T> it)
{
    // if it node is empty
    if (it.getNode() == nullptr)
    {
        throw "Invalid Iterator";
    }

    // if head is empty
    if (head == nullptr)
    {
        throw "Empty Iterable";
    }

    shared_ptr<Node<T>> temp = head;

    while(temp != it.getNode())
    {
        temp = temp->next;
    }

    if(temp == head)
    {
        head = temp->next;
    }
    else if(temp == tail)
    {
        tail = temp->prev;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    _size--;
}

}; // namespace Aysegul_GTU

#endif // ITERABLE_H
