/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tn;

void getSum(tn *root, int num, int *sum)
{
    if (root != NULL)
    {
        num = num * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
            *sum += num;
        else
        {
            getSum(root->left, num, sum);
            getSum(root->right, num, sum);
        }
    }
}

int sumNumbers(struct TreeNode* root)
{
    int *sum = (int*)malloc(sizeof(int));
    *sum = 0;
    getSum(root, 0, sum);
    return *sum;
}
