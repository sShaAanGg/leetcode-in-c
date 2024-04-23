// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tmp = new ListNode();  // tmp before the head
        ListNode* tail = tmp;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1) {  // list1 isn't nullptr
            tail->next = list1;
        } 
        if (list2) {  // list2 isn't nullptr
            tail->next = list2;
        }
        
        ListNode* head = tmp->next;  // the head after tmp
        delete tmp;
        return head;
    }
};
