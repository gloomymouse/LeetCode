/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head)
{
    if (head == NULL)
        return NULL;
        
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // if there is a cycle, the fast pointer and slow pointer will meet
    while (1)
    {
        if (fast == NULL || fast->next == NULL)
            return NULL;
        else
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
    }
    
    // two pointer begin from the head node and the meeint node with the same speed
    // they will meet at the node where the cycle begins
    slow = head;
    while (1)
    {
        if (slow == fast)
            return slow;
        else
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
}
