#include <stdexcept>
#include "list.h"

template <typename T>
bool List<T>::empty() const {
    return _size == 0;
}

template <typename T>
int List<T>::size() const {
    return _size;
}

template <typename T>
T List<T>::get_first() const {
    if (empty()) {
        throw std::runtime_error("Cannot get: List is empty.");
    }
    return head->data;
}

template <typename T>
T List<T>::get_last() const {
    if (empty()) {
        throw std::runtime_error("Cannot get: List is empty.");
    }
    return tail->data;
}

template <typename T>
T List<T>::get(int index) const {
    if (index < 0 || index > _size - 1) {
        throw std::runtime_error("Cannot get: index out of range.");
    }
    if (empty()) {
        throw std::runtime_error("Cannot get: List is empty.");
    }

    int i = 0;
    Node<T>* mover = head;
    while (mover) {
        if (i == index) {
            return mover->data;
        }
        mover = mover->next;
        i++;
    }
}

template <typename T>
void List<T>::set(int index, T value) const {
    if (index < 0 || index > _size - 1) {
        throw std::runtime_error("Cannot get: index out of range.");
    }
    if (empty()) {
        throw std::runtime_error("Cannot get: List is empty.");
    }

    int i = 0;
    Node<T>* mover = head;
    while (mover) {
        if (i == index) {
            break;
        }
        mover = mover->next;
        i++;
    }

    mover->data = value;
}

template <typename T>
void List<T>::insert_first(T value) {
    Node<T>* newHead = new Node(value);
    newHead->next = head;
    head = newHead;
    _size++;
    if (empty()) {
        tail = head;
    }
}

template <typename T>
void List<T>::insert_last(T value) {
    Node<T>* newTail = new Node(value);
    _size++;

    if (empty()) {
        head = newTail;
        tail = newTail;
        return;
    }

    tail->next = newTail;
    tail = newTail;
}

template <typename T>
void List<T>::remove_first() {
    if (empty()) {
        throw std::runtime_error("Cannot remove: List is empty.");
    }
    head = head->next;
    _size--;
    if (!head || !(head->next)) {
        tail = head;
    }
}

template <typename T>
void List<T>::remove_last() {
    if (empty()) {
        throw std::runtime_error("Cannot remove: List is empty.");
    }
    _size--;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node<T>* prev = head;
    while (prev->next != tail) {
        prev = prev->next;
    }

    prev->next = nullptr;
    tail = prev;

    if (head == tail) {
        head = tail;
    }
}

template <typename T>
void List<T>::insert_at(int index, T value) {
    if (index < 0 || index > _size - 1) {
        throw std::runtime_error("Cannot get: index out of range.");
    }
    if (empty()) {
        throw std::runtime_error("Cannot get: List is empty.");
    }
    _size++;

    if (index == 0) {
        insert_first(value);
        return;
    }
    else if (index == _size - 1) {
        insert_last(value);
        return;
    }

    Node<T>* prev = head;
    int i = 0;
    while (prev->next) {
        if (i + 1 == index) {
            break;
        }
        prev = prev->next;
        i++;
    }

    Node<T>* newNode = new Node(value);
    newNode->next = prev->next;
    prev->next = newNode;
}

template <typename T>
void List<T>::delete_at(int index) {
    if (index < 0 || index > _size - 1) {
        throw std::runtime_error("Cannot get: index out of range.");
    }
    if (empty()) {
        throw std::runtime_error("Cannot get: List is empty.");
    }
    _size--;

    if (index == 0) {
        remove_first();
        return;
    }
    else if (index == _size - 1) {
        remove_last();
        return;
    }


    Node<T>* prev = head;
    int i = 0;
    while (prev->next) {
        if (i + 1 == index) {
            break;
        }
        prev = prev->next;
        i++;
    }

    prev->next = prev->next->next;
}
