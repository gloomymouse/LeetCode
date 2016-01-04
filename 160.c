/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;
    
    // convert the List B to a loop
    struct ListNode *cur = headB;
    while (cur->next != NULL)
        cur = cur->next;
    struct ListNode *tail = cur;
    cur->next = headB;
    
    // if the List A has a loop, there is a interscetion
    cur = headA;
    struct ListNode *fast = headA;
    while (1)
    {
        if (fast == NULL || fast->next == NULL)
        {
            tail->next = NULL;  // convert the List B back to a single linked list
            return NULL;
        }
        else
        {
            cur  = cur->next;
            fast = fast->next->next;
            if (cur == fast)
                break;
        }
    }

    cur = headA;
    while (1)
    {
        if (cur == fast)
        {
            tail->next = NULL;  // convert the List B back to a single linked list
            return cur;
        }
        else
        {
            cur  = cur->next;
            fast = fast->next;
        }
    }
}
