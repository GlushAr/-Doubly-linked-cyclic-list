template<typename T> class CyList {
    private: 

        int count = 0; 

        typedef struct Node {
            struct Node* prev;
            struct Node* next;
            T info;
        } List;

        List* head;

        List* Init(T data) {
            count++;
            List* list = (List*)malloc(sizeof(List));
            List* tmp = list;
            list->info = data;
            list->prev = tmp;
            list->next = tmp; 
        return list;
        }

    public:

        void add(T data) {
            if(count != 0) {
                count++;
                List* list = (List*)malloc(sizeof(List));
                list->info = data;
                list->prev = head->prev;
                list->next = head;
                head->prev->next = list;
                head->prev = list;

            } else {
                head = Init(data);
            }
        }

        int size() {
            return count;
        }

        void print_all_info() {
            List* tmp = head;
            for(int i = 1; i <= count; i++) {
                std::cout << "iteration: " <<  i << " value: " << tmp->info << std::endl;
                tmp = tmp->next;
            }
        }

        void delete_node(List* node) {
            if(node == head)
                head = head->next;
            if(head == NULL)
                return;
            node->next->prev = node->prev;
            node->prev->next = node->next;
            free(node); 
            count--;
        }

        T operator [] (int i) {
            List* tmp = head;
            for (int k = 1; k < i; k++) tmp = tmp->next;
            return tmp->info;
        }

        List* get_ptr(int i) {
            List* tmp = head;
            for (int k = 1; k < i; k++) tmp = tmp->next;
            return tmp;
        }

        CyList(T data) {
            head = Init(data);
        }

        CyList() {

        }

        ~CyList() {
            if (count <= 1)
                free(head);
            else {
                head->prev->next = NULL;
                while(head != NULL) {
                    List* tmp = head;
                    head = head->next;
                    free(tmp);
                }
            }
        }
};
