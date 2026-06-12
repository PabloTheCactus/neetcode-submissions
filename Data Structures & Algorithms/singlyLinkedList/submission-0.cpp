class ListNode{
    public:
    int val;
    ListNode* next;
    
    ListNode(int _val): val(_val), next{nullptr}{}
    ListNode(int _val, ListNode* _next): val{_val}, next{_next}{}
};

class LinkedList {
    ListNode* head;
    ListNode* tail;
public:
    LinkedList() {
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode* curr = head->next;//ListNode* curr = new ListNode(head); не можна тому що конструктор чекає значень int або int _val, ListNode* _next
        int i = 0;//УВАГА head->next тому що head це dummy node тупо уявна нода
        while(curr != nullptr){//тут не curr->next != nullptr тому що ця умова пропустить останній елемент тому тут curr != nullptr
            if(i == index) return curr->val;
            i++;
            curr = curr->next;
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;// тут ми сказали що значення на яке вказує head тепер нова нода також на нього буде вказувати
        head->next = newNode;//і оскільки head уявний і він знаходиться на самісінькому початку листа то ми робимо так що head вказує на значення яке ми тіки шо вставили
        if(newNode->next == nullptr) tail = newNode;
    }
    
    void insertTail(int val) {
        ListNode* newNode = new ListNode(val);
        tail->next = newNode;//замість nullptr тепер tail->next = newNode. 
        tail = newNode;//а тут ми кажемо шо tail = newNode він має якесь значення, але конструктор каже шо він вказує на nullptr
        //або tail->next = new ListNode(val);
        //tail = tail->next; вони ідентичні
        //tail->next = nullptr тут його не треба це робить конструктор
    }

    bool remove(int index) {
        ListNode* curr = head;
        int i = 0;
        while(curr->next != nullptr){
            if(i == index){
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;//тобто наступна нода дорівнює ноді після неї
                if(tmp == tail) tail = curr;//або якщо curr->next бо ми поки що не видалили її
                delete tmp;//53 рядок ми там tail = curr бо ми видалили по факту останній елемент || ну а тут по факту ми просто звільнили память ноди (та нода була привязана адресою туда тому ми її і знесли)
                return true;
            }
            i++;
            curr = curr->next;
        }
        return 0;
    }

    vector<int> getValues() {
        ListNode* curr = head->next;//ще раз head це dummy node, вона уявна, і ми її не включаємо
        vector<int> res;
        int i = 0;
        while(curr != nullptr){
            res.push_back(curr->val);
            i++;
            curr = curr->next;
        }
        return res;
    }
};
