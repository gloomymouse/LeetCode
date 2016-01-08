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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (listsSize == 1)
        return lists[0];
    int i;
    for (i = 0; i < listsSize; i++)
    {
        if (lists[i] == NULL)
            continue;
        break;
    }
    if (i == listsSize)
        return NULL;
    ln *head = lists[i];
    ln *cur  = head;
    
    // merge k lists to get a new linked list
    while (1)
    {
        if (cur->next == NULL)
        {
            i++;
            if (i == listsSize)
                break;
            while (lists[i] == NULL && i < listsSize)
                i++;
            if (i == listsSize)
                break;
            cur->next = lists[i];
        }
        cur = cur->next;
    }
    // sort the new linked list using merge sort
    return MergeSort(head, NULL);
}

// The following method gets TLE (Time Limit Exceeded).
/*
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (listsSize == 1)
        return lists[0];
        
    ln *p[listsSize];
    int i;
    for (i = 0; i < listsSize; i++)
        p[i] = lists[i];
        
    ln *dumphead = (ln*)malloc(sizeof(ln));
    int pos = 0;
    for (i = 0; i < listsSize; i++)
    {
        if (lists[i] == NULL)
        {
            if (i == pos)
                pos++;
            continue;
        }
        if (lists[pos]->val > lists[i]->val)
            pos = i;
    }
    ln *cur = lists[pos];
    dumphead->next = cur;
    p[pos] = p[pos]->next;

    int sum = 0;
    ln *next;
    while (1)
    {
        sum = 0;
        for (i = 0; i < listsSize; i++)
        {
            if (p[i] == NULL)
                sum++;
        }
        if (sum == listsSize)
            break;
        
        pos = 0;
        for (i = 0; i < listsSize; i++)
        {
            if (p[i] == NULL)
            {
                if (i == pos)
                    pos++;
                continue;
            }
            if (p[pos]->val > p[i]->val)
                pos = i;
        }
        if (cur->next == p[pos])
        {
            cur = cur->next;
            p[pos] = p[pos]->next;
            continue;
        }
        next = cur->next;
        cur->next = p[pos];
        cur = p[pos];
        p[pos] = p[pos]->next;
    }
    cur->next = NULL;
    
    return dumphead->next;
}
*/
