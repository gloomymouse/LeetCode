/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* constructMaximumNode(int* nums, int left, int right) {
    if (left > right) {
        return NULL;
    }
    int max = 0;
    int pos = 0;
    for (int i = left; i <= right; i++) {
        if (max <= nums[i]) {
            max = nums[i];
            pos = i;
        }
    }
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = max;
    node->left = constructMaximumNode(nums, left, pos - 1);
    node->right = constructMaximumNode(nums, pos + 1, right);
    return node;
}


struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    return constructMaximumNode(nums, 0, numsSize - 1);
}
