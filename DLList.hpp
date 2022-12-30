#pragma once
#ifndef DLLIST_HPP
#define DLLIST_HPP

#include <iostream>

template <class T>
class Node
{
public:
    T data;
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;
};
template <class T>
class DLList
{
private:
    int size = 0;
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    bool boundCheck(int index);

public:
    T input;
    DLList(){};
    DLList(std::initializer_list<T> const l);
    ~DLList();

    int getSize() const { return size; }; /* read-only */

    void insert(T data, int index);
    void append(T data);
    void remove(int index);
    void pop();

    T &operator[](int index);

    void operator=(DLList<T> &list);
    void operator=(std::initializer_list<T> const l);

    void operator+=(T data);
    void operator+=(DLList<T> &list);
    void operator+=(std::initializer_list<T> const l);

    template <class U>
    friend std::ostream &operator<<(std::ostream &out, DLList<U> &list);
    template <class U>
    friend std::istream &operator>>(std::istream &in, DLList<U> &list);
};

template <class T>
bool DLList<T>::boundCheck(int index)
{
    Node<T> *iter = head;
    for (int i = 0; i < index; i++)
    {
        if (iter == NULL)
        {
            return false;
        }
        iter = iter->next;
    }
    return true;
};

template <class T>
DLList<T>::DLList(std::initializer_list<T> const l)
{
    for (auto i : l)
    {
        this->append(i);
    }
};
template <class T>
DLList<T>::~DLList()
{
    Node<T> *ptr = head;
    while (ptr != nullptr)
    {
        Node<T> *temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
};

template <class T>
void DLList<T>::insert(T data, int index)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    if (head == nullptr)
    {
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
        size++;
        return;
    }
    if (index == 0)
    {
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
        size++;
        return;
    }
    else if (index == size)
    {
        newNode->prev = tail;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
        size++;
        return;
    }
    else
    {
        newNode->next = nullptr;
        newNode->prev = nullptr;
        Node<T> *ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        newNode->next = ptr;
        newNode->prev = ptr->prev;
        ptr->prev->next = newNode;
        ptr->prev = newNode;
        size++;
    }
};
template <class T>
void DLList<T>::append(T data)
{
    insert(data, size);
}
template <class T>
void DLList<T>::remove(int index)
{
    if (boundCheck(index))
    {
        Node<T> *ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        if (ptr->prev == nullptr)
        {
            head = ptr->next;
            head->prev = nullptr;
        }
        else if (ptr->next == nullptr)
        {
            tail = ptr->prev;
            tail->next = nullptr;
        }
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }
        delete ptr;
        size--;
    }
    else
    {
        std::cout << "Index out of bounds" << std::endl;
    }
};

template <class T>
void DLList<T>::pop()
{
    remove(size - 1);
};

/* I N D E X */
template <class T>
T &DLList<T>::operator[](int index)
{
    if (index >= size || boundCheck(index) == false)
    {
        throw std::out_of_range("Index out of bound.");
    }
    Node<T> *ptr = head;
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->next;
    }
    return ptr->data;
};

/* A S S I G N M E N T */
template <class T>
void DLList<T>::operator=(DLList<T> &list)
{
    if (this == &list)
        return;
    this->~DLList();
    DLList<T> *temp = new (this) DLList<T>(); /* implicitly reconstructing */
    for (int i = 0; i < list.getSize(); i++)
    {
        this->append(list[i]);
    }
};
template <class T>
void DLList<T>::operator=(std::initializer_list<T> const l)
{
    this->~DLList();
    DLList<T> *temp = new (this) DLList<T>();
    for (auto i : l)
    {
        this->append(i);
    }
};

/* P L U S   E Q U A L S */
template <class T>
void DLList<T>::operator+=(T data)
{
    this->append(data);
};
template <class T>
void DLList<T>::operator+=(DLList<T> &list)
{
    for (int i = 0; i < list.getSize(); i++)
    {
        this->append(list[i]);
    }
};
template <class T>
void DLList<T>::operator+=(std::initializer_list<T> const l)
{
    for (auto i : l)
    {
        this->append(i);
    }
};

/* L E F T   S H I F T */
template <class T>
std::ostream &operator<<(std::ostream &out, DLList<T> &list)
{
    for (int i = 0; i < list.getSize(); i++)
    {
        out << list[i] << ' ';
    }
    return out;
};

/* R I G H T   S H I F T */
template <class T>
std::istream &operator>>(std::istream &in, DLList<T> &list)
{
    T data;
    in >> data;
    list.append(data);
    return in;
};

#endif // DLLIST_HPP
