/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
 
typedef struct RandomListNode rl;

struct RandomListNode *copyRandomList(struct RandomListNode *head)
{
    if (head == NULL)
        return head;
    
    // 在每个节点之后插入新节点，复制所有内容到新节点
    // 此时，新节点random域指向旧节点
    rl *cur = head;
    while (cur != NULL)
    {
        rl *tmp = (rl*)malloc(sizeof(rl));
        tmp->label = cur->label;
        tmp->random = cur->random;
        tmp->next = cur->next;
        cur->next = tmp;
        cur = tmp->next;
    }
    
    // 将新节点的random域指向相应的新节点
    cur = head;
    while (cur != NULL)
    {
        if (cur->next->random != NULL)
            cur->next->random = cur->next->random->next;
        cur = cur->next->next;
    }
    
    // 将链表拆分成新旧两个链表
    // 单独完成该步骤而不与���上一步骤一同进行
    // 避免拆分后断裂前驱节点，使得random域找不到相应节点
    cur = head;
    rl *newhead = head->next;
    rl *tmp = head->next;
    while (tmp->next != NULL)
    {
        cur->next = tmp->next;
        tmp->next = tmp->next->next;
        cur = cur->next;
        tmp = tmp->next;
    }
    cur->next = NULL;
    
    return newhead;
}
