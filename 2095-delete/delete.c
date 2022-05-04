typedef struct ListNode {
    int val;
    struct ListNode *next;
};

#include <stdlib.h>
// My naive and straightforward solution
struct ListNode *deleteMiddle(struct ListNode *head){
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
    *indirect = (*indirect) ? (*indirect)->next : NULL; // Remove (not release) the node (list[index])
    return head;
}
