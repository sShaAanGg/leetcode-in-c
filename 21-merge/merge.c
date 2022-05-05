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
