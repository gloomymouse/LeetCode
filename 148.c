/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ln;

ln *Merge(ln *head, ln *midtail, ln *tail) 
{
    ln *midhead  = midtail->next;
    ln *dumphead = (ln*)malloc(sizeof(ln));
    ln *cur;
    ln *pi;
    ln *pj;
    
    if (head->val < midhead->val)
    {
        dumphead->next = head;
        pi  = head->next;
        cur = head;
        pj  = midhead;
    }
    else
    {
        dumphead->next = midhead;
        pj  = midhead->next;
        cur = midhead;
        pi  = head;
    }
    
    while (pi != midhead && pj != tail)
    {
        if (pi->val < pj->val)
        {
            cur->next = pi;
            cur = pi;
            pi = pi->next;
        }
        else
        {
            cur->next = pj;
            cur = pj;
            pj = pj->next;
        }
    }
    
    if (pi != pj)
    {
        if (pi == midhead)
            cur->next = pj;
        else if (pj == tail)
        {
            cur->next = pi;
            midtail->next = tail;
        }
    }
    return dumphead->next;
}

ln *MergeSort(ln *head, ln *tail)
{
    if (head != tail && head->next != tail)
    {
        ln *slow = head;
        ln *fast = head;
        while (fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ln *newhead = MergeSort(head, slow);
        ln *cur = newhead;
        while (cur->next != slow)
            cur = cur->next;
        cur->next = MergeSort(slow, tail);
        return Merge(newhead, cur, tail);
    }
    return head;
}

struct ListNode* sortList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    return MergeSort(head, NULL);
}
