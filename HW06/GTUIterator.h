#ifndef GTUITERATOR_H
#define GTUITERATOR_H

#include <iostream>
#include <memory>
#include <iterator>
#include "Node.h"

using namespace std;

namespace Aysegul_GTU{

template <typename T>
class GTUIterator : public std::iterator<std::random_access_iterator_tag, T> {
    public:
        GTUIterator();
        GTUIterator(shared_ptr<Node<T>> node);
        GTUIterator(const GTUIterator& other);
        GTUIterator& operator=(const GTUIterator& other);

        // move sementics
        GTUIterator(GTUIterator&& other);
        GTUIterator& operator=(GTUIterator&& other);

        // destructor
        ~GTUIterator();
        
        GTUIterator& operator++();
        GTUIterator operator++(int);
        GTUIterator& operator--();
        GTUIterator operator--(int);
        bool operator==(const GTUIterator& other) const;
        bool operator!=(const GTUIterator& other) const;
        
        // Those two functions are different from GTUIteratorConst, since they should be const
        T& operator*() const;
        T* operator->() const;

        // overload >

        GTUIterator operator-(int) const;
        GTUIterator operator+(int) const;

        //for std::sort
        int operator-(const GTUIterator& other) const;
        bool operator<(const GTUIterator& other) const;
        bool operator>(const GTUIterator& other) const;
        

        shared_ptr<Node<T>> getNode() const;
        void setNode(shared_ptr<Node<T>> node);
    private:
        shared_ptr<Node<T>> node;
};

// constructors
template<class T>
GTUIterator<T>::GTUIterator()
{
    this->node = nullptr;
}

template<class T>
GTUIterator<T>::GTUIterator(shared_ptr<Node<T>> node)
{
    this->node = node;
}

template<class T>  
GTUIterator<T>::GTUIterator(const GTUIterator<T>& other)
{
    this->node = other.node;
}

// move semantcis
template<class T>
GTUIterator<T>::GTUIterator(GTUIterator<T>&& other)
{
    this->node = other.node;
    other.node = nullptr;
}

template<class T>
GTUIterator<T>& GTUIterator<T>::operator=(GTUIterator<T>&& other)
{
    this->node = other.node;
    other.node = nullptr;
    return *this;
}

// destructor
template<class T>
GTUIterator<T>::~GTUIterator()
{
    this->node = nullptr;
}
    
// setters and getters
template <typename T>
void GTUIterator<T>::setNode(shared_ptr<Node<T>> node) {this->node = node;}

template <typename T>
shared_ptr<Node<T>> GTUIterator<T>::getNode() const { return this->node;}


// expected iterator functions
template<class T> 
GTUIterator<T>& GTUIterator<T>::operator=(const GTUIterator<T>& other)
{
    this->node = other.node;
    return *this;
}

template<class T>
GTUIterator<T>& GTUIterator<T>::operator++()
{
    this->node = this->node->next;
    return *this;
}

template<class T>
GTUIterator<T> GTUIterator<T>::operator++(int)
{
    GTUIterator<T> temp(*this); // create a copy of the current object
    this->node = this->node->next;
    return temp;
}

template<class T>
GTUIterator<T>& GTUIterator<T>::operator--()
{
    if (this->node->prev == nullptr)
    {
        //cout << "Hay mk" << endl;
        this->node = this->node->next;
    }
    else
    {
        //cout << "Hay mk2" << endl;
        this->node = this->node->prev;
    }
    return *this;
}

template<class T>
GTUIterator<T> GTUIterator<T>::operator--(int)
{
    GTUIterator<T> temp(*this); // create a copy of the current object
    if (this->node->prev != nullptr)
        this->node = this->node->prev;

    return temp;
}

template<class T>
bool GTUIterator<T>::operator==(const GTUIterator<T>& other) const
{
    return *(this->node) == *(other.node);
}

template<class T>
bool GTUIterator<T>::operator!=(const GTUIterator<T>& other) const
{
    return !(*(this->node) == *(other.node));
}


template<class T>
T& GTUIterator<T>::operator*() const
{
    return this->node->getData();
}

template<class T>
T* GTUIterator<T>::operator->() const
{
    return &(this->node->getData());
}

template<class T>
GTUIterator<T> GTUIterator<T>::operator+(int value) const
{
    GTUIterator<T> temp(*this);
    for(int i = 0; i < value; i++)
    {
        temp.node = temp.node->next;
    }
    return temp;
}

template<class T>
GTUIterator<T> GTUIterator<T>::operator-(int value) const
{
    // create a copy of the current object
    GTUIterator<T> temp(*this);
    for(int i = 0; i < value; ++i)
    {
        temp.node = temp.node->prev;
    }

    return temp;
}

template<class T>
int GTUIterator<T>::operator-(const GTUIterator<T>& other) const
{
    int count = 0;
    GTUIterator<T> temp(*this);
    while(temp != other)
    {
        temp.node = temp.node->prev;
        count++;
    }
    return count;
}

template<class T>
bool GTUIterator<T>::operator>(const GTUIterator<T>& other) const
{
    // if null, return false
    if (this->node == nullptr || other.node == nullptr)
        return false;

    return this->node->data > other.node->data;
}

template<class T>
bool GTUIterator<T>::operator<(const GTUIterator<T>& other) const
{
    // if null, return false
    if (this->node == nullptr || other.node == nullptr)
        return false;

    return this->node->data < other.node->data;
}

}; // namespace Aysegul_GTU

#endif
