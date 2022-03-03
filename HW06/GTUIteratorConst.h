#ifndef GTUITERATORCONST_H
#define GTUITERATORCONST_H

#include <iostream>
#include <memory>
#include <iterator>
#include "Node.h"

using namespace std;

namespace Aysegul_GTU{

template <typename T>
class GTUIteratorConst : public std::iterator<std::random_access_iterator_tag, T> {
public:
    GTUIteratorConst();
    GTUIteratorConst(shared_ptr<Node<T>> node);
    GTUIteratorConst(const GTUIteratorConst& other);

    // move sementics
    GTUIteratorConst(GTUIteratorConst&& other);
    GTUIteratorConst& operator=(GTUIteratorConst&& other);

    // destructor
    ~GTUIteratorConst();

    GTUIteratorConst& operator=(const GTUIteratorConst& other);

    GTUIteratorConst& operator++();
    GTUIteratorConst operator++(int);
    GTUIteratorConst& operator--();
    GTUIteratorConst operator--(int);
    bool operator==(const GTUIteratorConst& other) const;
    bool operator!=(const GTUIteratorConst& other) const;

    // those two functions are different from GTUITerator, since they should be const
    const T& operator*() const;
    const T* operator->() const;

    // overload >
    bool operator>(const GTUIteratorConst& other) const;

    GTUIteratorConst operator-(int) const;
    GTUIteratorConst operator+(int);

    //for std::sort
    GTUIteratorConst operator-();

    shared_ptr<Node<T>> getNode() const;
    void setNode(shared_ptr<Node<T>> node);

private:

    shared_ptr<Node<T>> node;
};

// expected std::algorithm functions. I can't manage them properly, so I made my own versions
// template <typename T>
// void sort(GTUIteratorConst<T>, GTUIteratorConst<T>);

// template <typename T>
// void for_each(GTUIteratorConst<T>, GTUIteratorConst<T>, void (*func)(T&));

// sort and for_each functions are not valid for const iterator since this is not possible to change the values of the elements
template <typename T>
GTUIteratorConst<T> find(GTUIteratorConst<T>, GTUIteratorConst<T>, const T&);


// constructors
template<class T>
GTUIteratorConst<T>::GTUIteratorConst()
{
    this->node = nullptr;
}

template<class T>
GTUIteratorConst<T>::GTUIteratorConst(shared_ptr<Node<T>> node)
{
    this->node = node;
}

template<class T>  
GTUIteratorConst<T>::GTUIteratorConst(const GTUIteratorConst<T>& other)
{
    this->node = other.node;
}

// move semenatics
template<class T>
GTUIteratorConst<T>::GTUIteratorConst(GTUIteratorConst<T>&& other)
{
    this->node = other.node;
    other.node = nullptr;
}

template<class T>
GTUIteratorConst<T>& GTUIteratorConst<T>::operator=(GTUIteratorConst<T>&& other)
{
    this->node = other.node;
    other.node = nullptr;
    return *this;
}

// destructor
template<class T>
GTUIteratorConst<T>::~GTUIteratorConst()
{
    this->node = nullptr;
}
    
// setters and getters
template <typename T>
void GTUIteratorConst<T>::setNode(shared_ptr<Node<T>> node) {this->node = node;}

template <typename T>
shared_ptr<Node<T>> GTUIteratorConst<T>::getNode() const { return this->node;}


// expected iterator functions
template<class T> 
GTUIteratorConst<T>& GTUIteratorConst<T>::operator=(const GTUIteratorConst<T>& other)
{
    this->node = other.node;
    return *this;
}

template<class T>
GTUIteratorConst<T>& GTUIteratorConst<T>::operator++()
{
    this->node = this->node->next;
    return *this;
}

template<class T>
GTUIteratorConst<T> GTUIteratorConst<T>::operator++(int)
{
    GTUIteratorConst<T> temp(*this); // create a copy of the current object
    this->node = this->node->next;
    return temp;
}

template<class T>
GTUIteratorConst<T>& GTUIteratorConst<T>::operator--()
{
    this->node = this->node->prev;
    return *this;
}

template<class T>
GTUIteratorConst<T> GTUIteratorConst<T>::operator--(int)
{
    GTUIteratorConst<T> temp(*this); // create a copy of the current object
    this->node = this->node->prev;
    return temp;
}

template<class T>
bool GTUIteratorConst<T>::operator==(const GTUIteratorConst<T>& other) const
{
    return this->node == other.node;
}

template<class T>
bool GTUIteratorConst<T>::operator!=(const GTUIteratorConst<T>& other) const
{
    return !(this->node == other.node);
}


template<class T>
const T& GTUIteratorConst<T>::operator*() const
{
    return this->node->getData();
}

template<class T>
const T* GTUIteratorConst<T>::operator->() const
{
    return &(this->node->getData());
}

template<class T>
GTUIteratorConst<T> GTUIteratorConst<T>::operator+(int value)
{
    for(int i = 0; i < value; ++i)
    {
        node = node->next;
    }
    return *this;
}

template<class T>
GTUIteratorConst<T> GTUIteratorConst<T>::operator-(int value) const
{
    for(int i = 0; i < value; ++i)
    {
        node = node->prev;
    }
    return *this;
}

template<class T>
GTUIteratorConst<T> GTUIteratorConst<T>::operator-()
{
    node = node->prev;
    return *this;
}

template<class T>
bool GTUIteratorConst<T>::operator>(const GTUIteratorConst<T>& other) const
{
    return this->node->data > other.node->data;
}

// find function
template <typename T>
GTUIteratorConst<T> find(GTUIteratorConst<T> begin, GTUIteratorConst<T> end, const T& value)
{
    GTUIteratorConst<T> it = begin;
    end++;
    while(it != end)
    {
        if(*it == value)
        {
            return it;
        }
        it++;
    }
    return end;
}


} // namespace Aysegul_GTU


#endif