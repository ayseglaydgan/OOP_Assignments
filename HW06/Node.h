#ifndef NODE_H
#define NODE_H

#include <memory>

using namespace std;

namespace Aysegul_GTU{

template <class T>
class Node {
public:
    Node();
    Node(T data);
    Node(const Node& other);

    // move sementics
    Node(Node&& other);
    Node& operator=(Node&& other);

    // destructor
    ~Node();

    // assignment operator
    Node& operator=(const Node& other);

    T& getData();
    bool operator==(const Node<T>& other);
    bool operator!=(const Node<T>& other);

    T data;
    shared_ptr< Node<T> > prev;
    shared_ptr< Node<T> > next;
};


template <class T>
Node<T>::Node()
{
    this->prev = nullptr;
    this->next = nullptr;
}

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
}

// copy constructor
template <class T>
Node<T>::Node(const Node& other) {
    this->data = other.data;
    this->prev = other.prev;
    this->next = other.next;
}

// assignment operator
template <class T>
Node<T>& Node<T>::operator=(const Node<T>& other) {
    this->data = other.data;
    this->prev = other.prev;
    this->next = other.next;
    return *this;
}

// move sementics
template <class T>
Node<T>::Node(Node&& other) {
    this->data = other.data;
    this->prev = other.prev;
    this->next = other.next;
    other.prev = nullptr;
    other.next = nullptr;
}

template <class T>
Node<T>& Node<T>::operator=(Node<T>&& other) {
    this->data = other.data;
    this->prev = other.prev;
    this->next = other.next;
    other.prev = nullptr;
    other.next = nullptr;
    return *this;
}

// destructor
template <class T>
Node<T>::~Node() {
    this->prev = nullptr;
    this->next = nullptr;
}


// getters
template <class T>
T& Node<T>::getData() {
    return this->data;
}

template <class T>
bool Node<T>::operator==(const Node<T>& other) {


    return this->data == other.data;// && this->prev == other.prev && this->next == other.next;
}

template <class T>
bool Node<T>::operator!=(const Node<T>& other) {
    return !(*this == other);
}



}; // end of namespace

#endif