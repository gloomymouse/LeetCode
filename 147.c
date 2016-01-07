/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ln;

struct ListNode* insertionSortList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
        
    ln *cur  = head->next;
    ln *next = head->next;
    ln *newhead = head;
    ln *newtail = head;
    ln *tmp = head;
    
    while (cur != NULL)
    {
        next = cur->next;
        if (cur->val >= newtail->val) // 如果被插入数据比插入区间内所有数据都大，则不遍历插入区间列表
        {
            newtail = cur;
            cur = next;
            continue;
        }
        while (tmp != newtail || newhead == newtail)
        {
            if (cur->val < tmp->val)
            {
                cur->next = tmp;
                newhead = cur;
                newtail->next = next;
                tmp = newhead;
                break;
            }
            else if (cur->val >= tmp->val && cur->val <= tmp->next->val)
            {
                cur->next = tmp->next;
                tmp->next = cur;
                newtail->next = next;
                tmp = newhead;
                break;
            }
            tmp = tmp->next;
        }
        cur = next;
    }

    return newhead;
}
