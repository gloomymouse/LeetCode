/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int rangeSumBST(struct TreeNode* root, int L, int R){
    if (root == NULL) {
        return 0;
    }
    int ans = 0;
    ans = rangeSumBST(root->left, L, R);
    ans += rangeSumBST(root->right, L, R);
    
    if (L <= root->val && root->val <= R) {
        ans += root->val;
    }
    
    return ans;
}
