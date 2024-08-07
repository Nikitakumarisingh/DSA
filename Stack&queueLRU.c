//QUESTION:  Implement a LRU cache.
//CODE: 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node *head;
    Node *tail;
    Node **hashmap;
} LRUCache;

Node* createNode(int key, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *cache = (LRUCache *)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = createNode(0, 0);  // Dummy head
    cache->tail = createNode(0, 0);  // Dummy tail
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;
    cache->hashmap = (Node **)malloc(10000 * sizeof(Node *)); // Example size of hashmap
    memset(cache->hashmap, 0, 10000 * sizeof(Node *));
    return cache;
}

void moveToHead(LRUCache *cache, Node *node) {
    // Remove node from its current position
    node->prev->next = node->next;
    node->next->prev = node->prev;

    // Insert node right after head
    node->next = cache->head->next;
    node->prev = cache->head;
    cache->head->next->prev = node;
    cache->head->next = node;
}

void removeTail(LRUCache *cache) {
    Node *tail = cache->tail->prev;
    tail->prev->next = cache->tail;
    cache->tail->prev = tail->prev;
    cache->hashmap[tail->key] = NULL;
    free(tail);
}

int lRUCacheGet(LRUCache *cache, int key) {
    Node *node = cache->hashmap[key];
    if (!node) {
        return -1;
    }
    moveToHead(cache, node);
    return node->value;
}

void lRUCachePut(LRUCache *cache, int key, int value) {
    Node *node = cache->hashmap[key];
    if (node) {
        node->value = value;
        moveToHead(cache, node);
    } else {
        Node *newNode = createNode(key, value);
        cache->hashmap[key] = newNode;
        newNode->next = cache->head->next;
        newNode->prev = cache->head;
        cache->head->next->prev = newNode;
        cache->head->next = newNode;
        cache->size++;

        if (cache->size > cache->capacity) {
            removeTail(cache);
            cache->size--;
        }
    }
}

void lRUCacheFree(LRUCache *cache) {
    Node *current = cache->head;
    while (current) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(cache->hashmap);
    free(cache);
}

int main() {
    LRUCache *cache = lRUCacheCreate(2);
    
    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);
    printf("Get 1: %d\n", lRUCacheGet(cache, 1)); // returns 1
    lRUCachePut(cache, 3, 3); // evicts key 2
    printf("Get 2: %d\n", lRUCacheGet(cache, 2)); // returns -1 (not found)
    lRUCachePut(cache, 4, 4); // evicts key 1
    printf("Get 1: %d\n", lRUCacheGet(cache, 1)); // returns -1 (not found)
    printf("Get 3: %d\n", lRUCacheGet(cache, 3)); // returns 3
    printf("Get 4: %d\n", lRUCacheGet(cache, 4)); // returns 4

    lRUCacheFree(cache);
    return 0;
}
