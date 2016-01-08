/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tn;

int getMinDepth(tn *root, int depth)
{
    depth++;
    if (root->left == NULL && root->right == NULL)
        return depth;
    else
    {
        
        if (root->left != NULL && root->right == NULL)
            return getMinDepth(root->left, depth);
        else if (root->left == NULL && root->right != NULL)
            return getMinDepth(root->right, depth);
        else
        {
            int left  = getMinDepth(root->left, depth);
            int right = getMinDepth(root->right, depth);
            return left<right?left:right;
        }
    }
}

int minDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return getMinDepth(root, 0);
}
