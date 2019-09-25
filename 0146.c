typedef struct LRUNode {
    int key;
    int val;
    struct LRUNode* hash_next;
    struct LRUNode* list_prev;
    struct LRUNode* list_next;
} LRUNode;


typedef struct {
    int cap;
    int cnt;
    LRUNode** hash;
    LRUNode* LRUList;
} LRUCache;

void printlru(LRUCache* obj) {
    printf("lru: ");
    LRUNode* head = obj->LRUList;
    LRUNode* node = head;
    if (node == NULL) {
        printf("null");
    }
    while (node != NULL) {
        printf("%d|%d, ", node->key, node->val);
        if (node->list_next != head) {
            node = node->list_next;
        } else {
            break;
        }
    }
    printf("\n");
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* lru = (LRUCache*)malloc(sizeof(LRUCache));
    lru->cap = capacity;
    lru->cnt = 0;
    lru->hash = (LRUNode**)malloc(sizeof(LRUNode*)*capacity);
    for (int i = 0; i < capacity; i++) {
        lru->hash[i] = NULL;
    }
    lru->LRUList = NULL;
    return lru;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if (obj == NULL || obj->cap == 0) {
        return -1;
    }
    LRUNode* node = obj->hash[key % obj->cap];
    while (node != NULL) {
        if (node->key == key) {
            if (obj->LRUList != node) {
                node->list_prev->list_next = node->list_next;
                node->list_next->list_prev = node->list_prev;
                node->list_prev = obj->LRUList->list_prev;
                node->list_prev->list_next = node;
                node->list_next = obj->LRUList;
                obj->LRUList->list_prev = node;
                obj->LRUList = node;
            }
            return node->val;
        }
        node = node->hash_next;
    }
    return -1;
}

void lRUDelLast(LRUCache* obj) {
    if (obj == NULL || obj->cap == 0) {
        return;
    }
    LRUNode* last = obj->LRUList->list_prev;
    if (last->list_prev == last) {
        obj->LRUList = NULL;
    } else {
        obj->LRUList->list_prev = last->list_prev;
        last->list_prev->list_next = obj->LRUList;
    }
    
    LRUNode* head = obj->hash[last->key % obj->cap];
    if (head == NULL) {
        return;
    }
    LRUNode* node = head;
    while (node != NULL) {
        LRUNode* next = node->hash_next;
        if (node == last) {
            obj->hash[node->key % obj->cap] = next;
            break;
        } else if (next == last) {
            node->hash_next = next->hash_next;
            break;
        }
        node = next;
    }
    free(last);
    obj->cnt--;
    return;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if (obj == NULL || obj->cap == 0) {
        return;
    }
    int val = lRUCacheGet(obj, key);
    if (val == -1) {
        if (obj->cnt == obj->cap) {
            lRUDelLast(obj);
        }
        LRUNode* node = (LRUNode*)malloc(sizeof(LRUNode));
        node->key = key;
        node->val = value;
        node->list_prev = node;
        node->list_next = node;
        if (obj->LRUList != NULL) {
            node->list_prev = obj->LRUList->list_prev;
            node->list_prev->list_next = node;
            node->list_next = obj->LRUList;
            obj->LRUList->list_prev = node;
        }
        obj->LRUList = node;
        LRUNode* buck = obj->hash[key % obj->cap];
        if (buck == NULL) {
            obj->hash[key % obj->cap] = node;
        } else {
            while (buck->hash_next != NULL) {
                buck = buck->hash_next;
            }
            buck->hash_next = node;
        }
        node->hash_next = NULL;
        obj->cnt++;
    } else if (val != value) {
        obj->LRUList->val = value;
    }
    return;
}

void lRUCacheFree(LRUCache* obj) {
    if (obj == NULL) {
        return;
    }
    while (obj->LRUList != NULL) {
        lRUDelLast(obj);
    }
    return;
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
