#include <stdlib.h>
#include <stdint.h>

typedef struct ListNode {
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
        // *indirect = (*indirect)->next; => It's wrong. It will cause the head point to either list1->next or list2->next
    }
    // Either list1 points to null or list2
    *indirect = (struct ListNode *) ((uintptr_t) list1 | (uintptr_t) list2);
    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0)
        return NULL;
    
    while (listsSize > 1) {
        for (int i = 0, j = listsSize - 1; i < j; i++) {
            // Merge the first list and the last list in 1 iteration
            lists[i] = mergeTwoLists(lists[i], lists[j]);
            j--;
        }
        listsSize = (listsSize + 1) / 2;
    }
    
    return lists[0];
}

// Use divide and conquer with mergeTwoLists() and mergeKLists()
// struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
//     if (!listsSize)
//         return NULL;
//     if (listsSize <= 1) // Avoid underflow from the shift expression below
//         return *lists;

//     int m = listsSize >> 1; //int m = listSize / 2; if listsSize == 1 => underflow
//     struct ListNode *left = mergeKLists(lists, m);
//     struct ListNode *right = mergeKLists(lists + m, listsSize - m); // (lists + m) points to the m-th element in lists

//     return mergeTwoLists(left, right);
// }
