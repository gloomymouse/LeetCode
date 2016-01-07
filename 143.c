/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return;
        
    struct ListNode *dumphead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dumphead->next = head;
    
    struct ListNode *tmp2 = dumphead;
    struct ListNode *tmp1 = dumphead;
    while (tmp1 != NULL && tmp1->next != NULL)
    {
        tmp2 = tmp2->next;
        tmp1 = tmp1->next->next;
    }
    
    // reverse the latter half of the list
    struct ListNode *preReverse = tmp2;
    tmp2 = tmp2->next;
    tmp1 = tmp2->next;
    struct ListNode *old;
    
    while (tmp1 != NULL)
    {
        old = tmp1->next;
        tmp1->next = tmp2;
        tmp2 = tmp1;
        tmp1 = old;
    }
    preReverse->next->next = tmp1;
    preReverse->next = tmp2;
    
    // re-link the list
    // refer to the merge-sort of linked list (148.c)
    old = preReverse->next;
    tmp1 = head->next;
    struct ListNode *cur = head;
    int flag = 1;
    while (1)
    {
        if (tmp1 == old && tmp2 == NULL)
            break;
        if (flag == 2)
        {
            cur->next = tmp1;
            cur = tmp1;
            tmp1 = tmp1->next;
            flag = 1;
        }
        else if (flag == 1)
        {
            cur->next = tmp2;
            cur = tmp2;
            tmp2 = tmp2->next;
            flag = 2;
        }
    }
    cur->next = NULL;
}
