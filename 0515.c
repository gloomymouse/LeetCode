/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void GetValue(struct TreeNode* root, int* ans, int* num, int layer) {
    if (root == NULL) {
        return;
    }
    
    if (ans[layer] < root->val) {
        ans[layer] = root->val;
    }
    
    if (*num < layer + 1) {
        *num = layer + 1;
    }
    
    GetValue(root->left, ans, num, layer + 1);
    GetValue(root->right, ans, num, layer + 1);
    return;
}

int* largestValues(struct TreeNode* root, int* returnSize){
    int* ans = (int*)malloc(sizeof(int) * 1000);
    for (int i = 0; i < 1000; i++) {
        ans[i] = -2147483648;
    }
    int num = 0;
    GetValue(root, ans, &num, 0);
    
    *returnSize = num;
    return ans;
}
