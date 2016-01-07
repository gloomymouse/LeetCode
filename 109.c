/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct ListNode ln;
typedef struct TreeNode tn;

tn *convert(ln *head, ln *tail)
{
    if (head == NULL || head == tail)
        return NULL;
        
    tn *parent = (tn*)malloc(sizeof(tn));
    if (head->next == tail)
    {
        parent->val = head->val;
        parent->left = NULL;
        parent->right = NULL;
        return parent;
    }
    
    ln *slow = head;
    ln *fast = head;
    while (fast != tail && fast->next != tail)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    parent->val = slow->val;
    parent->left = convert(head, slow);
    parent->right = convert(slow->next, tail);
    return parent;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    if (head == NULL)
        return NULL;
    return convert(head, NULL);
}
