#include "IntVec.h"
#include <iostream>

void print_vec(IntVec &vec) {
  std::cout << "{";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec.at(i);
    if (i != vec.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "}";
  std::cout << std::endl;
}

void print_size(IntVec &vec) {
  std::cout << "Size: " << vec.size() << std::endl;
}

void print_capacity(IntVec &vec) {
  std::cout << "Capacity: " << vec.capacity() << std::endl;
}

void print_vec_info(IntVec &vec) {
  print_vec(vec);
  print_size(vec);
  print_capacity(vec);
}

int main(void) {
  IntVec vec;
  std::cout << vec.data() << std::endl;
  print_vec_info(vec);

  vec.push_back(10);
  print_vec_info(vec);

  vec.push_back(20);
  print_vec_info(vec);

  vec.push_back(30);
  print_vec_info(vec);

  std::cout << vec.pop_back() << std::endl;
  print_vec_info(vec);

  std::cout << "Element at 1: " << vec.at(1) << std::endl;

  vec.pop_back();
  print_vec_info(vec);
  vec.pop_back();
  print_vec_info(vec);
  vec.push_back(1);
  print_vec_info(vec);
  vec.insert(0, 3);
  print_vec_info(vec);

  vec.insert(1, 30);
  print_vec_info(vec);

  vec.insert(1, 30);
  print_vec_info(vec);

  vec.insert(2, 30);
  print_vec_info(vec);

  vec.insert(4, 30);
  print_vec_info(vec);

  vec.at(100);

  return 0;
}
