/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *dumphead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dumphead->next = head;
    
    if (head == NULL || head->next == NULL)
        return head;
    
    struct ListNode *cur = head;
    struct ListNode *tmp = head->next;
    int isDup = 0;
    while (tmp != NULL)
    {
        if (cur->val == tmp->val)
        {
            tmp = tmp->next;
            if (isDup == 0)
                isDup = 1;
            continue;
        }
        if (cur->val != tmp->val && isDup == 0)
        {
            tmp = tmp->next;
            cur = cur->next;
            continue;
        }
        if (cur->val != tmp->val && isDup == 1)
        {
            cur->next = tmp;
            isDup = 0;
            tmp = tmp->next;
            cur = cur->next;
        }
    }
    cur->next = tmp;
    return dumphead->next;
}
