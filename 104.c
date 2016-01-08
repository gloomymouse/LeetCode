/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tn;

int getMaxDepth(tn *root, int depth)
{
    depth++;
    if (root->left == NULL && root->right == NULL)
        return depth;
    else
    {
        
        if (root->left != NULL && root->right == NULL)
            return getMaxDepth(root->left, depth);
        else if (root->left == NULL && root->right != NULL)
            return getMaxDepth(root->right, depth);
        else
        {
            int left  = getMaxDepth(root->left, depth);
            int right = getMaxDepth(root->right, depth);
            return left>right?left:right;
        }
    }
}

int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return getMaxDepth(root, 0);
}
