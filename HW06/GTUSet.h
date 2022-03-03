#ifndef GTUSET_H
#define GTUSET_H
#include <iostream>
#include <memory>
#include <initializer_list> // for using arr = {1,2,3,4,5} initialization
#include "Iterable.h"

using namespace std;

namespace Aysegul_GTU{

template <class T>
class GTUSet : public Iterable<T> // Inheritance
{
public:
    GTUSet();
    GTUSet(T);
    GTUSet(const GTUSet& other); //copy constructor
    GTUSet(const initializer_list<T>& list); //initializer list constructor
    GTUSet& operator=(const GTUSet& other);

    // move constructor
    GTUSet(GTUSet&& other);
    GTUSet& operator=(GTUSet&& other);

    // destructor
    ~GTUSet() override;


    GTUIterator<T> begin() const override;
    GTUIterator<T> end() const override;
    int size() const override;
    bool empty() const override;
    void erase(GTUIterator<T> it) override;
    void clear() override;
    const GTUIteratorConst<T> cbegin() const override;
    const GTUIteratorConst<T> cend() const override;

    // Set Functions
    void add(const T& value);
    // delete function
    void remove(const T& value);

    // intersect function   
    GTUSet<T> intersect(const GTUSet<T>& other) const;
    // union function
    GTUSet<T> unionSet(const GTUSet<T>& other) const;
    
private:
    // contains function
    // since this function is not needed for the set, I made it private
    bool contains(const T& value) const;
};

template <class T>
GTUSet<T>::GTUSet()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;
}

template <class T>
GTUSet<T>::GTUSet(T value)
{
    this->head = shared_ptr<Node<T>>(new Node<T>(value));
    this->tail = this->head;
    this->_size = 1;
}

template <class T>
GTUSet<T>::GTUSet(const GTUSet& other)
{
    this->head = other.head;
    this->tail = other.tail;
    this->_size = other._size;
}

template <class T>
GTUSet<T>& GTUSet<T>::operator=(const GTUSet& other)
{
    this->head = other.head;
    this->tail = other.tail;
    this->_size = other._size;
    return *this;
}

// move constructor
template <class T>
GTUSet<T>::GTUSet(GTUSet&& other)
{
    this->head = other.head;
    this->tail = other.tail;
    this->_size = other._size;
    other.head = nullptr;
    other.tail = nullptr;
    other._size = 0;
}

template <class T>
GTUSet<T>& GTUSet<T>::operator=(GTUSet&& other)
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
GTUSet<T>::~GTUSet()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;
}

template <class T>
GTUSet<T>::GTUSet(const initializer_list<T>& list)
{
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        this->add(*it);
    }
}

template <typename T> 
GTUIterator<T> GTUSet<T>::begin() const
{
    return Iterable<T>::begin();
}

template <typename T>
GTUIterator<T> GTUSet<T>::end() const
{
    return Iterable<T>::end();
}

template <typename T>
int GTUSet<T>::size() const
{
    return Iterable<T>::size();
}

template <typename T>
bool GTUSet<T>::empty() const
{
    return Iterable<T>::empty();
}

template <typename T>
void GTUSet<T>::erase(GTUIterator<T> it)
{
    Iterable<T>::erase(it);
}

template <typename T>
void GTUSet<T>::clear()
{
    Iterable<T>::clear();
}

template <typename T>
const GTUIteratorConst<T> GTUSet<T>::cbegin() const
{
    return Iterable<T>::cbegin();
}

template <typename T>
const GTUIteratorConst<T> GTUSet<T>::cend() const
{
    return Iterable<T>::cend();
}


// set functions
template <typename T>
void GTUSet<T>::add(const T& value)
{
    shared_ptr<Node<T>> newNode(new Node<T>(value));
    if(this->head == nullptr)
    {
        this->head = newNode;
        this->tail = newNode;
        this->_size++;
    }
    else
    {
        if(this->contains(value))
        {
            return;
        }
        else
        {
            newNode->prev = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
            this->_size++;
        }
    }
    
}

template <typename T>
void GTUSet<T>::remove(const T& value)
{
    if(this->empty())
    {
        return;
    }
    else
    {
        // check if contains than it could be removed
        if(contains(value))
        {
            shared_ptr<Node<T>> temp = this->head;
            shared_ptr<Node<T>> prev = nullptr;
            while(temp != nullptr)
            {
                if(temp->data == value)
                {
                    // if first node
                    if(prev == nullptr)
                    {
                        this->head = temp->next;
                        temp->next = nullptr;
                        this->_size--;
                        break;
                    }
                    else
                    {
                        prev->next = temp->next;
                        temp->next = nullptr;
                        this->_size--;
                        break;
                    }
                }
                prev = temp;
                temp = temp->next;
            }
        }
    }
}

template <typename T>
GTUSet<T> GTUSet<T>::intersect(const GTUSet<T>& other) const
{
    // throw err if empty
    if (this->empty() || other.empty()) {
        throw "Empty Set";
    }

    GTUSet<T> result;
    GTUIterator<T> it = this->begin();
    while(it != this->end())
    {
        if(contains(*it))
        {
            result.add(*it);
        }
        it++;
    }
    return result;
}

template <typename T>
GTUSet<T> GTUSet<T>::unionSet(const GTUSet<T>& other) const
{
    // throw err if empty+
    if (this->empty() || other.empty()) {
        throw "Empty Set";
    }

    GTUSet<T> result;
    GTUIterator<T> it = this->begin();
    while(it != this->end())
    {
        result.add(*it);
        it++;
    }
    it = other.begin();
    while(it != other.end())
    {
        result.add(*it);
        it++;
    }
    return result;
}


// helper contains function
template <typename T>
bool GTUSet<T>::contains(const T& value) const
{
    if(this->empty())
    {
        return false;
    }
    else
    {
        GTUIteratorConst<T> it = this->cbegin();
        
        while(it != this->cend())
        {
            if(*it == value)
            {
                return true;
            }
            it++;
        }
        return false;
    }
}



    
}; // end of namespace


#endif  // GTUSet_H