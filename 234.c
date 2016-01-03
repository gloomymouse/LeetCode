/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head)
{
    struct ListNode *dumphead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dumphead->next = head;
    
    if (head == NULL || head->next == NULL)
        return true;
    
    struct ListNode *old = head;
    int n = 0;
    int m = 0;
    while (old != NULL)
    {
        old = old->next;
        n++;
    }
    m = n / 2 -1;
    
    old  = head->next;
    struct ListNode *tmp1 = head;
    struct ListNode *tmp2 = dumphead;
    
    while (m--)   // Reverse the first half of the linked list
    {
        tmp1->next = tmp2;
        tmp2 = tmp1;
        tmp1 = old;
        old = old->next;
    }
    
    tmp1->next = tmp2;
    head->next = NULL;
    
    if (n % 2 != 0)
        old = old->next;
    
    while (tmp1 != NULL)
    {
        if (tmp1->val != old->val)
            return false;
        else
            tmp1 = tmp1->next;
            old = old->next;
    }
    return true;
}
