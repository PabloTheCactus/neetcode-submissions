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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* fast = head;
        ListNode* slow = dummy;
        while(n--){fast = fast->next;}//ми за межі не вийдемо n <= sz

        while(fast!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;//n не може бути менше за 1 тому ця умова завжди буде правильна завдяки dummy бо якщо навіть 1 тільки елемент буде то slow->next буде nullptr а slow -1 як ми ініціалізували спочатку
        delete tmp;

        ListNode* res = dummy->next;//ми видаляємо саму ноду dummy
        delete dummy;
        return res;

    }
};
