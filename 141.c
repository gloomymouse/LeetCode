/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    if (head == NULL)
        return false;
        
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    
    while (1)
    {
        if (fast == NULL || fast->next == NULL)
            return false;
        else if (slow == fast)
            return true;
        else
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
}
