/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tn;

bool partSum(tn *root, int sum, int tmp)
{
    if (root == NULL)
        return false;
    tmp += root->val;
    if (root->left == NULL && root->right == NULL)
    {
        if (tmp == sum)
            return true;
        else
            return false;
    }
    else
        return (partSum(root->left, sum, tmp) || partSum(root->right, sum, tmp));
}

bool hasPathSum(struct TreeNode* root, int sum)
{
    return partSum(root, sum, 0);
}
