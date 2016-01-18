/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ln;

struct ListNode* oddEvenList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ln *odd = head;
    ln *even = head->next;
    ln *evenhead = head->next;
    bool isOdd = true;
    while (odd != NULL && even != NULL)
    {
        if (isOdd)
        {
            odd->next = even->next;
            if (odd->next != NULL)
                odd = odd->next;
            isOdd = false;
        }
        else
        {
            even->next = odd->next;
            even = even->next;
            isOdd = true;
        }
    }
    odd->next = evenhead;
    if (even != NULL)
        even->next = NULL;
    return head;
}
