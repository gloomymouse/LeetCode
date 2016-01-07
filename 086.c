/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ln;

struct ListNode* partition(struct ListNode* head, int x)
{
    if (head == NULL || head->next == NULL)
        return head;
        
    ln *lesshead = NULL;
    ln *lesstail = NULL;
    ln *greaterhead = NULL;
    ln *greatertail = NULL;
    ln *cur = head;
    
    while (cur != NULL)
    {
        if (cur->val < x)
        {
            if (lesshead == NULL)
            {
                lesshead = cur;
                lesstail = cur;
            }
            else
            {
                lesstail->next = cur;
                lesstail = cur;
            }
        }
        else
        {
            if (greaterhead == NULL)
            {
                greaterhead = cur;
                greatertail = cur;
            }
            else
            {
                greatertail->next = cur;
                greatertail = cur;
            }
        }
        cur = cur->next;
    }
    
    if (lesshead == NULL)
        return greaterhead;
    else if (greaterhead == NULL)
        return lesshead;
    else
    {
        lesstail->next = greaterhead;
        greatertail->next = NULL;
        return lesshead;
    }
}
