/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tn;

// 递归法，交换一棵树的所有节点的左右子树
tn *exchange(tn *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return root;
    tn *tmp;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    if (root->left != NULL)
        root->left = exchange(root->left);
    if (root->right != NULL)
        root->right = exchange(root->right);
    return root;
}

bool isSameTree(tn *p, tn *q)
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

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL)
        return true;
    // 交换根节点左子树下所有节点的左右子树    
    root->left = exchange(root->left);
    // 交换后的左子树，与右子树完全相等，则该树对称
    return isSameTree(root->left, root->right);
}
