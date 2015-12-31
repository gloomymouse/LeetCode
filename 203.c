/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode *dumphead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dumphead->next = head;
    
    if (head == NULL)
        return head;
    
    struct ListNode *tmp = dumphead;
    
    while (tmp->next != NULL)
    {
        if (tmp->next->val == val)
        {
            tmp->next = tmp->next->next;
            if (tmp->next == NULL)
                break;
        }
        else
            tmp = tmp->next;
        
    }
    return dumphead->next;
}
