/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    char* str = (char*)malloc(100000);
    struct TreeNode* queue[100000];
    int head = 0;
    int tail = 0;
    
    str[0] = '\0';
    queue[0] = root;
    tail++;
    while (head < tail) {
        struct TreeNode* node = queue[head++];
        if (node != NULL) {
            sprintf(str, "%s%d,", str, node->val);
            queue[tail++] = node->left;
            queue[tail++] = node->right;
        } else {
            sprintf(str, "%s,", str);
        }
    }
    //printf("%s\n", str);
    return str;
}

void GetVal(char* data, int* val, int* next) {
    int pos = 0;
    while (data[pos] != ',') {
        pos++;
    }
    //data[pos] = '\0';
    *val = atoi(data);
    *next = pos;
    return;
}

struct ListNode* GenNode(char* cur_data, char** next_data) {
    int val = 0;
    int next = 0;
    struct TreeNode* new = NULL;
    GetVal(cur_data, &val, &next);
    if (next != 0) {
        new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        new->val = val;
    }
    *next_data = cur_data + next + 1;
    return new; 
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    struct TreeNode* queue[100000];
    int head = 0;
    int tail = 0;
    char* cur_data = data;

    struct TreeNode* root = GenNode(cur_data, &cur_data);
    queue[tail++] = root;
    
    while (head < tail) {
        struct TreeNode* node = queue[head++];
        if (node != NULL) {
            node->left = GenNode(cur_data, &cur_data);
            queue[tail++] = node->left;
            node->right = GenNode(cur_data, &cur_data);
            queue[tail++] = node->right;
        }
    }
    
    return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
