/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;
        
    struct ListNode *dumphead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dumphead->next = head;
    struct ListNode *cur = head;

    int n = 0;
    while (cur != NULL)
    {
        cur = cur->next;
        n++;
    }
    
    if (k % n == 0)
        return head;
    n = n - (k % n) - 1;
    
    cur = head;
    while (n--)
        cur = cur->next;

    dumphead->next = cur->next;
    cur->next = NULL;
    cur = dumphead->next;

    while (cur->next != NULL)
        cur = cur->next;
    cur->next = head;
    
    return dumphead->next;
}
