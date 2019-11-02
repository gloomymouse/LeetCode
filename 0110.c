/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool CheckBalance(struct TreeNode* root, int* height) {
    int left_height = 0;
    int right_height = 0;
    int height_diff = 0;
    bool balance = true;
    
    if (root == NULL) {
        return true;
    }
    
    left_height = *height + 1;
    right_height = *height + 1;
    
    balance = CheckBalance(root->left, &left_height);
    if (balance == false) {
        return false;
    }
    
    balance = CheckBalance(root->right, &right_height);
    if (balance == false) {
        return false;
    }
    
    height_diff = left_height - right_height;
    if (height_diff < -1 || height_diff > 1) {
        return false;
    }
    
    *height = (height_diff > 0) ? left_height : right_height;
    return true;
}

bool isBalanced(struct TreeNode* root){
    int height = 0;
    return CheckBalance(root, &height);
}
