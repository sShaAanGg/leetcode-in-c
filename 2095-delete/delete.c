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
