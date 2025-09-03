#ifndef INTVEC_H
#define INTVEC_H
#include <cstddef>

class IntVec
{
private:
    int *_data;
    size_t _size;
    size_t _capacity;
    void deallocate_data();
    void resize(size_t new_capacity);
    size_t get_new_capacity_value();
    void validate_index(int index);
    void get_k_free_places_from(int index, int k);

public:
    IntVec();
    IntVec(int *arr, size_t size);
    ~IntVec();
    int *data();
    size_t size();
    size_t capacity();
    bool is_empty();
    int front();
    int back();
    int at(int index);
    void push_back(int value);
    void push_front(int value); // add new item to the start
    int pop_back();
    void insert(int index, int value);
    int delete_at(int index);
    bool remove(int value);
    int find(int value);
};

#endif
