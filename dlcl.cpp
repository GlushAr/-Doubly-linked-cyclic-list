#include <iostream>
#include <stdlib.h>
#include "DLCyList.cpp"

int main() {
    CyList <int>list;
    for (int i = 1; i <= 10; i++)
        list.add(i);
    list.print_all_info();
    std::cout << "size of list: " << list.size() << std::endl;
    
    return 0;
}