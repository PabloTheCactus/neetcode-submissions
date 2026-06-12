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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num = 0;
        int k = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(l1 || l2){
            if(l1 == nullptr) num = l2->val;
            else if(l2 == nullptr) num = l1->val;
            else num = l1->val + l2->val;
            if(num + k >= 10){
                tail->next = new ListNode((num + k) % 10, nullptr);
                k=1;
                tail = tail->next;
            }
            else{
                if(num + k >= 10){
                    tail->next = new ListNode((num + k) % 10, nullptr);
                    k = 1;
                }
                tail->next = new ListNode(num + k, nullptr);
                tail = tail->next;
                k = 0;
                
            }
            if(l1 == nullptr) l2 = l2->next;
            else if(l2 == nullptr) l1 = l1->next;
            else{
            l1 = l1->next;
            l2 = l2->next;
            }
        }
        if(k){
            tail->next = new ListNode(k, nullptr);
        }
        ListNode* tmp = dummy->next; 
        delete dummy;                
        return tmp;                  

    }
};
