#include <iostream>
#include <stdlib.h>
#include "DLCyList.cpp"

int main() {
    CyList <char>list;
    for (int i = 0; i <= 10; i++)
        list.add('A' + i);
    list.print_all_info();
    list.delete_node(list.get_ptr(5));
    std::cout << list[5] << std::endl;
    std::cout << "size of list: " << list.size() << std::endl;
    return 0;
}