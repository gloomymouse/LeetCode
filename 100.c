/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tn;

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;
    if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
        return false;
    if (p->val == q->val)
    {
        if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            return true;
        else
            return false;
    }
    return false;
}
