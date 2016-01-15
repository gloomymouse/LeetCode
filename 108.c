// please chect: https://leetcode.com/faq/#different-output
// These bugs could be hard to debug, so good luck. 
// Or just give up on C/C++ entirely and code in a more predictable language, like Java. Just kidding.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tn;

void toBST(tn *root, int *nums, int head, int tail)
{
    int mid = (head + tail) / 2;
    root->val = nums[mid];
    if (head <= mid - 1)
    {
        root->left = (tn*)malloc(sizeof(tn));
        toBST(root->left, nums, head, mid - 1);
    }
    else
        root->left == NULL;
    if (mid + 1 <= tail)
    {
        root->right = (tn*)malloc(sizeof(tn));
        toBST(root->right, nums, mid+1, tail);
    }
    else
        root->right == NULL;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    tn *root = (tn*)malloc(sizeof(tn));
    int head = 0;
    int tail = numsSize - 1;
    toBST(root, nums, head, tail);
    printf("trace\n");
    return root;
}
