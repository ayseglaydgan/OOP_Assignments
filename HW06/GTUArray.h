#ifndef GTUARRAY_H
#define GTUARRAY_H

#include <iostream>
#include <memory>
#include <initializer_list> // for using arr = {1,2,3,4,5} initialization
#include "Iterable.h"

using namespace std;

namespace Aysegul_GTU{

template <class T, int SIZE>
class GTUArray : public Iterable<T> // Inheritance
{
public:
    GTUArray();
    GTUArray(T);
    GTUArray(const GTUArray& other); //copy constructor
    GTUArray(const initializer_list<T>& list); //initializer list constructor
    GTUArray& operator=(const GTUArray& other);

    // move constructor
    GTUArray(GTUArray&& other);
    GTUArray& operator=(GTUArray&& other);

    // destructor
    ~GTUArray() override;

    GTUIterator<T> begin() const override;
    GTUIterator<T> end() const override;
    int size() const override;
    bool empty() const override;
    void erase(GTUIterator<T> it) override;
    void clear() override;
    const GTUIteratorConst<T> cbegin() const override;
    const GTUIteratorConst<T> cend() const override;


    // Array Functions
    T& at(int index) const;
    T& back() const;
    T& front() const;
    T* data() const;
    void fill(const T& value);
    int max_size() const;
    T& operator[](int index) const; 

private:
    int _SIZE = 0;

};

template <class T, int SIZE>
GTUArray<T, SIZE>::GTUArray()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = SIZE;
    this->_SIZE = SIZE;

    // create room for SIZE elements
    this->head = shared_ptr<Node<T>>(new Node<T>());
    shared_ptr<Node<T>> temp = this->head;
    for (int i = 0; i < SIZE - 1; i++)
    {
        temp->next = shared_ptr<Node<T>>(new Node<T>());
        temp->next->prev = temp;
        temp = temp->next;
        this->tail = temp;
    }

}

template <class T, int SIZE>
GTUArray<T, SIZE>::GTUArray(T value)
{
    this->head = shared_ptr<Node<T>>(new Node<T>(value));
    this->tail = this->head;
    this->_size = SIZE;
    this->_SIZE = SIZE;

    // create room for SIZE elements
    this->head = shared_ptr<Node<T>>(new Node<T>());
    shared_ptr<Node<T>> temp = this->head;
    for (int i = 0; i < SIZE - 1; i++)
    {
        temp->next = shared_ptr<Node<T>>(new Node<T>());
        temp->next->prev = temp;
        temp = temp->next;
        this->tail = temp;
    }

}

template <class T, int SIZE>
GTUArray<T, SIZE>::GTUArray(const GTUArray& other)
{
    this->head = other.head;
    this->tail = other.tail;
    this->_size = other._size;
    this->_SIZE = SIZE;

    // create room for SIZE elements
    this->head = shared_ptr<Node<T>>(new Node<T>());
    shared_ptr<Node<T>> temp = this->head;
    for (int i = 0; i < _SIZE - 1; i++)
    {
        temp->next = shared_ptr<Node<T>>(new Node<T>());
        temp->next->prev = temp;
        temp = temp->next;
        this->tail = temp;
    }
}

// move constructor
template <class T, int SIZE>
GTUArray<T, SIZE>::GTUArray(GTUArray&& other)
{
    this->head = other.head;
    this->tail = other.tail;
    this->_size = other._size;
    this->_SIZE = other._SIZE;
    other.head = nullptr;
    other.tail = nullptr;
    other._size = 0;
    other._SIZE = 0;
}

template <class T, int SIZE>
GTUArray<T, SIZE>& GTUArray<T, SIZE>::operator=(GTUArray&& other)
{
    if(this != &other)
    {
        this->head = other.head;
        this->tail = other.tail;
        this->_size = other._size;
        this->_SIZE = other._SIZE;
        other.head = nullptr;
        other.tail = nullptr;
        other._size = 0;
        other._SIZE = 0;
    }
    return *this;
}


// destructor
template <class T, int SIZE>
GTUArray<T, SIZE>::~GTUArray()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;
    this->_SIZE = 0;
}

template <class T, int SIZE>
GTUArray<T, SIZE>& GTUArray<T, SIZE>::operator=(const GTUArray& other)
{
    this->head = other.head;
    this->tail = other.tail;
    this->_size = other._size;
    return *this;
}

// initializer list constructor
template <class T, int SIZE>
GTUArray<T, SIZE>::GTUArray(const initializer_list<T>& list)
{
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = SIZE;
    this->_SIZE = SIZE;

    // if list size is bigger than SIZE, throw exception
    if (list.size() > SIZE)
    {
        throw "Initializer list size is bigger than array size";
    }

    // create room for SIZE elements
    this->head = shared_ptr<Node<T>>(new Node<T>());
    shared_ptr<Node<T>> temp = this->head;
    for (int i = 0; i < SIZE - 1; i++)
    {
        temp->next = shared_ptr<Node<T>>(new Node<T>());
        temp->next->prev = temp;
        temp = temp->next;
        this->tail = temp;
    }
    int i = 0;
    for(auto it = list.begin(); it != list.end(); ++it)
    {
        this->at(i++) = *it;
    }
}


template <class T, int SIZE>
GTUIterator<T> GTUArray<T, SIZE>::begin() const
{
    return Iterable<T>::begin();
}

template <class T, int SIZE>
GTUIterator<T> GTUArray<T, SIZE>::end() const
{
    return Iterable<T>::end();
}

template <class T, int SIZE>
int GTUArray<T, SIZE>::size() const
{
    return Iterable<T>::size();
}

template <class T, int SIZE>
bool GTUArray<T, SIZE>::empty() const
{
    return Iterable<T>::empty();
}

template <class T, int SIZE>
void GTUArray<T, SIZE>::erase(GTUIterator<T> it)
{
    Iterable<T>::erase(it);
}

template <class T, int SIZE>
void GTUArray<T, SIZE>::clear()
{
    Iterable<T>::clear();
}

template <class T, int SIZE>
const GTUIteratorConst<T> GTUArray<T, SIZE>::cbegin() const
{
    return Iterable<T>::cbegin();
}

template <class T, int SIZE>
const GTUIteratorConst<T> GTUArray<T, SIZE>::cend() const
{
    return Iterable<T>::cend();
}

// array functions
template <class T, int SIZE>
T& GTUArray<T, SIZE>::at(int index) const
{
    if(index < 0 || index >= SIZE)
    {
        throw "Index out of range";
    }
    else
    {
        int i = 0;
        GTUIterator<T> it = this->begin();
        while(i != index)
        {
            it++;
            i++;
        }
        return *it;
    }
}

template <class T, int SIZE>
T& GTUArray<T, SIZE>::back() const
{
    // if array empty
    if(this->empty())
    {
        throw "Array is empty";
    }

    return this->at(SIZE - 1);
}

template <class T, int SIZE>
T& GTUArray<T, SIZE>::front() const
{
    // if array empty
    if(this->empty())
    {
        throw "Array is empty";
    }

    return this->at(0);
}

template <class T, int SIZE>
T* GTUArray<T, SIZE>::data() const
{
    // if array empty
    if(this->empty())
    {
        throw "Array is empty";
    }

    T* arr = new T[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = this->at(i);
    }

    return arr;
}

template <class T, int SIZE>
void GTUArray<T, SIZE>::fill(const T& value)
{
    for (int i = 0; i < SIZE; i++)
    {
        this->at(i) = value;
    }
}

template <class T, int SIZE>
int GTUArray<T, SIZE>::max_size() const
{
    return _SIZE;
}

template <class T, int SIZE>
T& GTUArray<T, SIZE>::operator[](int index) const
{
    return this->at(index);
}


    
}; // end of namespace


#endif  // GTUSet_H