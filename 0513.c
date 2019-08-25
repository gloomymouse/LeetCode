/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int findBottomLeftValue(struct TreeNode* root){
    struct TreeNode* queue[10000];
    int head = 0;
    int tail = 0;
    int count = 0;
    int next_count = 0;
    struct TreeNode* leftmost = NULL;
    int ans = root->val;

    queue[tail++] = root;
    next_count = 1;
    
    while (head < tail) {
        struct TreeNode* node = queue[head++];
        count++;
        if (node->left != NULL) {
            queue[tail++] = node->left;
            if (leftmost == NULL) {
                leftmost = node->left;
                ans = leftmost->val;
            }
        }
        if (node->right != NULL) {
            queue[tail++] = node->right;
            if (leftmost == NULL) {
                leftmost = node->right;
                ans = leftmost->val;
            }
        }
        if (count == next_count) {
            next_count = tail - head;
            count = 0;
            leftmost = NULL;
        }
    }
    return ans;
}

