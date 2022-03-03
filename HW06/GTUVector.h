#ifndef GTUVECTOR_H
#define GTUVECTOR_H

#include <iostream>
#include <memory>
#include <initializer_list> // for using arr = {1,2,3,4,5} initialization
#include "Iterable.h"

using namespace std;

namespace Aysegul_GTU{

template <class T>
class GTUVector : public Iterable<T> // Inheritance
{
public:
    GTUVector();
    GTUVector(T);
    GTUVector(const GTUVector& other); //copy constructor
    GTUVector(const initializer_list<T>& list); //initializer list constructor
    GTUVector& operator=(const GTUVector& other);

    // move constructor
    GTUVector(GTUVector&& other);
    GTUVector& operator=(GTUVector&& other);

    // destructor
    ~GTUVector() override;


    GTUIterator<T> begin() const override;
    GTUIterator<T> end() const override;
    int size() const override;
    bool empty() const override;
    void erase(GTUIterator<T> it) override;
    void clear() override;
    const GTUIteratorConst<T> cbegin() const override;
    const GTUIteratorConst<T> cend() const override;

    // vector functions
    void add(const T& value);
    T& operator[](int index) const;
    

};

template <class T>
GTUVector<T>::GTUVector()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;
}

template <class T>
GTUVector<T>::GTUVector(T value)
{
    this->head = shared_ptr<Node<T>>(new Node<T>(value));
    this->tail = this->head;
    this->_size = 1;
}

template <class T>
GTUVector<T>::GTUVector(const GTUVector& other)
{
    this->head = other.head;
    this->tail = other.tail;
    this->_size = other._size;
}

template <class T>
GTUVector<T>& GTUVector<T>::operator=(const GTUVector& other)
{
    this->head = other.head;
    this->tail = other.tail;
    this->_size = other._size;
    return *this;
}

// intializer list constructor
template <class T>
GTUVector<T>::GTUVector(const initializer_list<T>& list)
{
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        this->add(*it);
    }
}

// move constructor
template <class T>
GTUVector<T>::GTUVector(GTUVector&& other)
{
    this->head = other.head;
    this->tail = other.tail;
    this->_size = other._size;
    other.head = nullptr;
    other.tail = nullptr;
    other._size = 0;
}

template <class T>
GTUVector<T>& GTUVector<T>::operator=(GTUVector&& other)
{
    if(this != &other)
    {
        this->head = other.head;
        this->tail = other.tail;
        this->_size = other._size;
        other.head = nullptr;
        other.tail = nullptr;
        other._size = 0;
    }
    return *this;
}


// destructor
template <class T>
GTUVector<T>::~GTUVector()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;
}

template <typename T> 
GTUIterator<T> GTUVector<T>::begin() const
{
    return Iterable<T>::begin();
}

template <typename T>
GTUIterator<T> GTUVector<T>::end() const
{
    return Iterable<T>::end();
}

template <typename T>
int GTUVector<T>::size() const
{
    return Iterable<T>::size();
}

template <typename T>
bool GTUVector<T>::empty() const
{
    return Iterable<T>::empty();
}

template <typename T>
void GTUVector<T>::erase(GTUIterator<T> it)
{
    Iterable<T>::erase(it);
}

template <typename T>
void GTUVector<T>::clear()
{
    Iterable<T>::clear();
}

template <typename T>
const GTUIteratorConst<T> GTUVector<T>::cbegin() const
{
    return Iterable<T>::cbegin();
}

template <typename T>
const GTUIteratorConst<T> GTUVector<T>::cend() const
{
    return Iterable<T>::cend();
}


// vector functions
template <typename T>
void GTUVector<T>::add(const T& value)
{
    // simple linked list add method
    shared_ptr<Node<T>> newNode(new Node<T>(value));
    if(this->head == nullptr)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->_size++;
}

template <typename T>
T& GTUVector<T>::operator[](int index) const
{
    if(index < 0 || index >= this->_size)
    {
        throw "Index out of range";
    }
    GTUIterator<T> it = begin();
    for(int i = 0; i < index; i++)
    {
        it++;
    }
    return *it;
}

    
}; // end of namespace


#endif  // GTUVECTOR_H