/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* cur = head;
	tmp = cur;
	int flag = 0;
	while (cur != NULL)
	{
		cur = cur->next;
		if (flag <= n)
		{
			flag++;
			continue;
		}
		tmp = tmp->next;
	}
	if (flag == n)
		return head->next;
	tmp->next = tmp->next->next;
	return head;
}
