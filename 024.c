/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head)
{
	struct ListNode* dumphead = (struct ListNode*)malloc(sizeof(struct ListNode));
	dumphead->next = head;
	struct ListNode* cur = dumphead;
	struct ListNode* tmp = NULL;
	if (head == NULL || head->next == NULL)
		return head;
	dumphead = head->next;

    while (cur->next != NULL)
    {
        if (cur->next->next == NULL)
            break;
		tmp = cur->next->next;
		cur->next->next = tmp->next;
		tmp->next = cur->next;
		cur->next = tmp;
		cur = cur->next->next;
    }
    return dumphead;
}
