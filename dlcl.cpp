#include <iostream>
#include <stdlib.h>

class CyList {
    private: 

        int count; 

        typedef struct Node {
            struct Node* prev;
            struct Node* next;
            char letter;
        } List;

        List* head;

        List* Init(char data) {
            count++;
            List* list = (List*)malloc(sizeof(List));
            List* tmp = list;
            list->letter = data;
            list->prev = tmp;
            list->next = tmp; 
        return list;
        }

    public:

        void add(char data) {
            List* start = head;
            count++;
            List* list = (List*)malloc(sizeof(List));
            list->letter = data;
            for(int i = 1; i < (count - 1); i++, start = start->next);
            List* tmp = start->next;
            list->prev = start;
            list->next = tmp;
            start->next = list;
            tmp->prev = list;
        }

        int size(){
            return count;
        }

        void print_all_info(){
            List* tmp = head;
            for(int i = 1; i <= count; i++) {
                printf("iteration: %d, value: %c\n", i, tmp->letter);
                tmp = tmp->next;
            }
        }

        CyList(char data){
            count = 0;
            head = Init(data);
        }
};

int main() {
    CyList list('A');
    list.add('B');
    list.add('C');
    list.add('D');
    list.add('E');
    list.print_all_info();
    std::cout << "size of list: " << list.size() << std::endl;
    return 0;
}