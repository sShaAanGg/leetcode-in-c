// Reference: https://hackmd.io/@sysprog/c-linked-list#%E4%BD%A0%E6%89%80%E4%B8%8D%E7%9F%A5%E9%81%93%E7%9A%84-C-%E8%AA%9E%E8%A8%80-linked-list-%E5%92%8C%E9%9D%9E%E9%80%A3%E7%BA%8C%E8%A8%98%E6%86%B6%E9%AB%94
struct ListNode {
    int val;
    struct ListNode *next;
};

#include <stdlib.h>
// My naive and straightforward solution
struct ListNode *deleteMiddle(struct ListNode *head)
{
    struct ListNode **indirect = &head;
    int size;
    // Iterate through the list to find out the size
    for (size = 0; *indirect; indirect = &(*indirect)->next) {
        size++;
    }
    int index = size / 2;
    // Iterate through the list to find out the node to be removed
    indirect = &head;
    for (int i = 0; i < index && *indirect; indirect = &(*indirect)->next) {
        i++;
    }
    // del points to the node which is going to be removed
    struct ListNode *del = *indirect;
    *indirect = (*indirect)->next; // Remove (not release) the node (list[index])
    free(del); // Release (free) the resource of the removed node
    return head;
}

// Solution with fast and slow pointer
struct ListNode *deleteMiddle(struct ListNode *head)
{
    struct ListNode **indirect = &head, *fast = head;
    /*
     * Fast pointer moves 2 times faster than indirect.
     * When fast iterates through the entre list,
     * indirect would points to the "middle" node.
     */
    for (; fast && fast->next ; fast = fast->next->next) {
        indirect = &(*indirect)->next;
    } 
    struct ListNode *del = *indirect;
    *indirect = (*indirect)->next;
    free(del);
    return head;
}
