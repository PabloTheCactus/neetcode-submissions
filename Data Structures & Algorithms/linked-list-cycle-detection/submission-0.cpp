/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fastptr = head;
        ListNode *slowptr = head;
        while(fastptr!=nullptr){
            fastptr = fastptr->next;
            if(fastptr == nullptr)return false;//ця умова тут обовязкова щоб ми не пропустили nullptr інакше помилка
            fastptr = fastptr->next;//воно так треба щоб ми ненароком за null не вийшли, бо присвоїмо next а то був nullptr а в nullptr нема next тому ще раз умова обовязкова
            
            slowptr = slowptr->next;
            if(fastptr == slowptr) return true;
        }
        return false;//є ліпший варіант цього коду в нотатках
    }
};