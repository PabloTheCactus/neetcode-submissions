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
//значить наново це комбінація трьох проблем шо я робив раніше
//для початку визначаємо середину повільним швидким пойнтером
//розвертаємо другу половину
//і перезєднуємо їх
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast = fast->next->next;
            slow=slow->next;
        }
        ListNode* curr = slow->next;
        ListNode* prev = slow->next = nullptr;//slow->next для того щоб воно зразу показувало на нуль ми розриваємо його на дві половинки
        while(curr!=nullptr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        while(prev){
            ListNode* tmp = head->next;
            ListNode* tmp2 = prev->next;
            head->next = prev;
            prev->next = tmp;
            head = tmp;
            prev = tmp2;
        }
    }
};
