// Reference: https://hackmd.io/@sysprog/c-linked-list#%E4%BD%A0%E6%89%80%E4%B8%8D%E7%9F%A5%E9%81%93%E7%9A%84-C-%E8%AA%9E%E8%A8%80-linked-list-%E5%92%8C%E9%9D%9E%E9%80%A3%E7%BA%8C%E8%A8%98%E6%86%B6%E9%AB%94
// https://medium.com/@orionssl/%E6%8E%A2%E7%B4%A2-floyd-cycle-detection-algorithm-934cdd05beb9
struct ListNode {
    int val;
    struct ListNode *next;
};

#include <stdbool.h>
#include <stddef.h>
static inline struct ListNode *move(struct ListNode *cur) { return cur ? cur->next : NULL; }
bool hasCycle(struct ListNode *head)
{
    struct ListNode *tortoise = head; // tortoise ats as a slow pointer
    struct ListNode *hare = head; // hare acts as a fast pointer
    while (hare && hare->next) {
        tortoise = move(tortoise);
        hare = move(move(hare));
        if (tortoise == hare) // If they meets at any node in the lise,
            return true; // then there is a cycle in the linked list
    }
    return false; // If hare doesn't meet tortoise at all, then there is no cycle.
}
