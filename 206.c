/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode *dumphead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dumphead->next = head;
    
    if (head == NULL || head->next == NULL)
        return head;
    
    struct ListNode *old  = head->next;
    struct ListNode *tmp1 = head;
    struct ListNode *tmp2 = dumphead;
    
    while (old != NULL)
    {
        tmp1->next = tmp2;
        tmp2 = tmp1;
        tmp1 = old;
        old = old->next;
    }
    tmp1->next = tmp2;
    head->next = NULL;
    return tmp1;
}
