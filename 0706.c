#define HASH_SIZE (1000000)

typedef struct {
    int size;
    int* data;
} MyHashMap;

/** Initialize your data structure here. */
MyHashMap* myHashMapCreate() {
    MyHashMap* hash = (MyHashMap*)malloc(sizeof(MyHashMap));
    if (hash != NULL) {
        hash->size = 0;
        hash->data = (int*)malloc(sizeof(int) * HASH_SIZE);
        if (hash->data != NULL) {
            hash->size = HASH_SIZE;
            for (int i = 0; i < hash->size; i++) {
                hash->data[i] = -1;
            }
        }
    }
    return hash;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    if (obj == NULL || obj->data == NULL) {
        return;
    }
    obj->data[key%HASH_SIZE] = value;
    return;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    if (obj == NULL || obj->data == NULL) {
        return -1;
    }
    return obj->data[key%HASH_SIZE];
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    if (obj == NULL || obj->data == NULL) {
        return;
    }
    obj->data[key%HASH_SIZE] = -1;
    return;
}

void myHashMapFree(MyHashMap* obj) {
    if (obj == NULL) {
        return;
    }
    if (obj->data != NULL) {
        free(obj->data);
        obj->data = NULL;
    }
    obj->size = 0;
    free(obj);
    return;
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
