/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool CheckValidAndGetMinMaxLeaf(struct TreeNode* root, int* min, int* max) {
    if (root == NULL) {
        return true;
    }
    
    bool ret;
    int min_l, min_r, max_l, max_r;
    if (root->left != NULL) {
        ret = CheckValidAndGetMinMaxLeaf(root->left, &min_l, &max_l);
        if (ret == false || root->val <= max_l) {
            return false;
        }
        *min = min_l;
    } else {
        *min = root->val;
    }
    if (root->right != NULL) {
        ret = CheckValidAndGetMinMaxLeaf(root->right, &min_r, &max_r);
        if (ret == false || root->val >= min_r) {
            return false;
        }
        *max = max_r;
    } else {
        *max = root->val;
    }
    return true;
}


bool isValidBST(struct TreeNode* root) {
    int min, max;
    return CheckValidAndGetMinMaxLeaf(root, &min, &max);
}
