#include <iostream>
#include "list.h"
using namespace std;

int main(void) {
    List<int> list1;
    list1.insert_first(1);
    list1.insert_at(0, 0);
    list1.delete_at(0);
    list1.insert_last(1);
    list1.delete_at(0);
    return 0;
}
