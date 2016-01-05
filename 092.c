/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    if (head == NULL || head->next == NULL)
        return head;
        
    struct ListNode *dumphead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dumphead->next = head;
    
    struct ListNode *tmp2 = dumphead;
    int pos = 1;
    while (pos < m)
    {
        tmp2 = tmp2->next;
        pos++;
    }
    
    struct ListNode *preReverse = tmp2; // preReverse Node is the pre-Node before the reverse-part list begins
    tmp2 = tmp2->next;
    struct ListNode *tmp1 = tmp2->next;
    struct ListNode *old;
    
    while (pos < n)
    {
        old = tmp1->next;
        tmp1->next = tmp2;
        tmp2 = tmp1;
        tmp1 = old;
        pos++;
    }
    preReverse->next->next = tmp1;  // the current tmp1 is the Node after the reverse-part list
    preReverse->next = tmp2;        // the current tmp2 is the tail Node of the reverse-part list
                                    // preReverse->next is the head Node of the reverse-part list
    return dumphead->next;
}
