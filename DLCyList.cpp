template<typename T> class CyList {
    private: 

        int count = 0; 

        typedef struct Node {
            struct Node* prev;
            struct Node* next;
            T letter;
        } List;

        List* head;

        List* Init(T data) {
            count++;
            List* list = (List*)malloc(sizeof(List));
            List* tmp = list;
            list->letter = data;
            list->prev = tmp;
            list->next = tmp; 
        return list;
        }

        List* Init() {
            List* list = (List*)malloc(sizeof(List));
            List* tmp = list;
            list->prev = tmp;
            list->next = tmp; 
        return list;
        }

    public:

        void add(T data) {
            if (count == 0) {
                count++;
                head->letter = data;
            } else {
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
        }

        int size() {
            return count;
        }

        void print_all_info() {
            List* tmp = head;
            for(int i = 1; i <= count; i++) {
                std::cout << "iteration: " <<  i << " value: " << tmp->letter << std::endl;
                tmp = tmp->next;
            }
        }

        CyList(T data) {
            head = Init(data);
        }

        CyList() {
            head = Init();
        }

        ~CyList() {
            head->prev->next = NULL;
            while(head != NULL) {
                List* tmp = head;
                head = head->next;
                free(tmp);
            }
        }
};
