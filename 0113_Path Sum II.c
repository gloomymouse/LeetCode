/* Path Sum II */
/********************************
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
********************************/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAX_SIZE (1024)

typedef struct AnsStruct {
    int cur_sum;
    int path_size;
    int path[MAX_SIZE];
    int ans_size;
    int* ans_col_size;
    int** ans;
} AnsStruct;

// DFS
void GetPath(struct TreeNode* root, int sum, AnsStruct* ans) {
    if (root == NULL) {
        return;
    }
    
    int cur_sum = ans->cur_sum + root->val;
    
    if ((cur_sum == sum) && (root->left == NULL && root->right == NULL)) {
        int ans_size = ans->ans_size;
        ans->ans_col_size[ans_size] = ans->path_size + 1;
        ans->ans[ans_size] = (int*)malloc(sizeof(int)*(ans->ans_col_size[ans_size]));
        ans->ans_size++;
        for (int i = 0; i < ans->path_size; i++) {
            ans->ans[ans_size][i] = ans->path[i];
        }
        ans->ans[ans_size][ans->path_size] = root->val;
    } else {
        ans->path[ans->path_size++] = root->val;
        ans->cur_sum = cur_sum;
        if (root->left != NULL) {
            GetPath(root->left, sum, ans);
        }
        if (root->right != NULL) {
            GetPath(root->right, sum, ans);
        }
        ans->path_size--;
        ans->cur_sum = cur_sum - root->val;
    }
    return;
}


int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    AnsStruct ans;
    //memset(&ans, 0, sizeof(AnsStruct));
    ans.cur_sum = 0;
    ans.path_size = 0;
    ans.ans_size = 0;
    ans.ans = (int**)malloc(sizeof(int*) * MAX_SIZE);
    ans.ans_col_size = (int*)malloc(sizeof(int) * MAX_SIZE);
    
    GetPath(root, sum, &ans);
    
    *returnSize = ans.ans_size;
    *returnColumnSizes = ans.ans_col_size;
    return ans.ans;
}

