// Reference: https://hackmd.io/@sysprog/c-linked-list#%E4%BD%A0%E6%89%80%E4%B8%8D%E7%9F%A5%E9%81%93%E7%9A%84-C-%E8%AA%9E%E8%A8%80-linked-list-%E5%92%8C%E9%9D%9E%E9%80%A3%E7%BA%8C%E8%A8%98%E6%86%B6%E9%AB%94
#include <stdlib.h>
#include <stdint.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *head;
    struct ListNode **indirect = &head, **node;

    for (node = NULL; list1 && list2; indirect = &(*indirect)->next) {
        node = (list1->val < list2->val) ? &list1 : &list2;
        *indirect = *node;
        *node = (*node)->next;
        /*
         * *node = (*node)->next; // It's right.
         * *indirect = (*indirect)->next; // It's wrong.
         * It will cause the head points to either list1->next or list2->next
         * and list1 and list2 won't move to next node.
        */
    }

    /*
     * Either list1 points to null or list2
     * Cast pointer to integer type for bitwise logical OR operation
    */
    *indirect = (struct ListNode *) ((uintptr_t) list1 | (uintptr_t) list2);
    return head;
}
