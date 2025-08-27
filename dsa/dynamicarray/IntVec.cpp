#include "IntVec.h"
#include <stdexcept>
#include <iostream>

IntVec::IntVec() : _data{nullptr}, _size{0}, _capacity{0} {};

IntVec::IntVec(int *arr) {
  if (arr == nullptr) {
    throw std::invalid_argument("Array cannot be null");
  }
}

IntVec::~IntVec() {
  deallocate_data();
}

void IntVec::deallocate_data() {
  if (_data) {
    delete[] _data;
  }
}

void IntVec::resize(int new_capacity) {
  if (new_capacity < 0) {
    deallocate_data();
    throw std::runtime_error("Capacity cannot be negative");
  }

  if (new_capacity == _capacity)
    return;
  int *new_arr = new int[new_capacity];
  int new_size = (new_capacity > _size) ? _size : new_capacity;

  for (int i = 0; i < new_size; i++) {
    new_arr[i] = _data[i];
  }

  deallocate_data();
  _data = new_arr;
  _capacity = new_capacity;
  _size = new_size;
}

int IntVec::get_new_capacity_value() {
  return (_capacity == 0) ? 1 : (_capacity * 2);
}

void IntVec::validate_index(int index) {
  if (index < 0 || index >= _size) {
    deallocate_data();
    throw std::out_of_range("Index out of range");
  }
}

void IntVec::get_k_free_places_from(int index, int k) {
  if (k <= 0)
    return;

  if (index != 0) {
    validate_index(index);
  }

  if (_size + k >= _capacity) {
    int new_capacity = get_new_capacity_value();
    if (new_capacity - _size < k) {
      new_capacity += k;
    }
    resize(new_capacity);
  }

  if (_size == 0)
    return;

  for (int i = _size - 1; i >= index; i--) {
    _data[i + k] = _data[i];
    _data[i] = 0;
  }
}

int *IntVec::data() { return _data; }

int IntVec::size() { return _size; }

int IntVec::capacity() { return _capacity; }

bool IntVec::is_empty() { return _size == 0; }

int IntVec::front() {
  if (is_empty()) {
    deallocate_data();
    throw std::runtime_error("Illegal access to empty array");
  }
  return _data[0];
}

int IntVec::back() {
  if (is_empty()) {
    deallocate_data();
    throw std::runtime_error("Illegal access to empty array");
  }
  return _data[_size - 1];
}

int IntVec::at(int index) {
  validate_index(index);
  return _data[index];
}

void IntVec::push_back(int value) {
  if (_size + 1 >= _capacity) {
    resize(get_new_capacity_value());
  }
  _data[_size++] = value;
}

void IntVec::push_front(int value) {
  get_k_free_places_from(0, 1);
  _data[0] = value;
  _size++;
}

int IntVec::pop_back() {
  if (_size == 0) {
    deallocate_data();
    throw std::runtime_error("No element to remove.");
  }
  int value = _data[--_size];
  return value;
}

void IntVec::insert(int index, int value) {
  get_k_free_places_from(index, 1);
  _data[index] = value;
  _size++;
}

int IntVec::delete_at(int index) {
  validate_index(index);
  for (int i = 0; i < _size - 1; i++) {
    int tmp = _data[i];
    _data[i] = _data[i + 1];
    _data[i + 1] = _data[i];
  }
  int value = _data[--_size]; // since the target element
                              // is moved to the end, decrement
  return value;
}

bool IntVec::remove(int value) {
  int index = find(value);
  if (index == -1) {
    return false;
  }

  delete_at(index);
  return true;
}

int IntVec::find(int value) {
  for (int i = 0; i < _size; i++) {
    if (_data[i] == value) {
      return i;
    }
  }
  return -1;
}
