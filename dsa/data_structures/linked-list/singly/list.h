#pragma once


template <typename T>
class Node;

template <typename T>
class List {
private:
    Node<T>* head {nullptr};
    Node<T>* tail {nullptr};
    int _size {0};
public:
    bool empty() const;
    int size() const;
    T get_first() const;
    T get_last() const;
    T get(int index) const;
    void set(int index, T value) const;
    void insert_first(T value);
    void insert_last(T value);
    void remove_first();
    void remove_last();
    void insert_at(int index, T value);
    void delete_at(int index);
};


template <typename T>
class Node {
private:
    T data;
    Node* next = {nullptr};
    friend class List<T>;
public:
    Node(T value)
        : data{ value }
    {}
};

#include "list.inl"
