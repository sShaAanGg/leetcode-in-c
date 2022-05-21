/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/

#include <stdlib.h>

typedef struct {
    int key;
    int value;
    ListNode *next;
} ListNode;

typedef struct {
    int capacitiy;
    int size;
    ListNode *head;
    ListNode *last;
} LRUCache;


LRUCache *lRUCacheCreate(int capacity)
{
    LRUCache *obj = malloc(sizeof(LRUCache));
    obj->capacitiy = capacity;
    obj->size = 0;
    obj->head = NULL;
    obj->last = NULL;
}

int lRUCacheGet(LRUCache *obj, int key)
{

}

void lRUCachePut(LRUCache *obj, int key, int value)
{

}

void lRUCacheFree(LRUCache *obj)
{
    free(obj);
}

void lRUCacheReorder(LRUCache * obj)
{

}
