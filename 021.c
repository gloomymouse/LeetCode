/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* tmp = NULL;
	struct ListNode* head = NULL;

	if (l1 == NULL && l2 == NULL)
	{
		return NULL;
	}
	else if (l1 == NULL)
	{
		return l2;
	}
	else if (l2 == NULL)
	{
		return l1;
	}

	if (l1->val <= l2->val)
	{
		tmp = l1;
		l1 = l1->next;
	}
	else
	{
		tmp = l2;
		l2 = l2->next;
	}
	head = tmp;
	
	while (l1 != NULL || l2 != NULL)
	{
		if (l1 == NULL)
		{
			tmp->next = l2;
			return head;
		}
		if (l2 == NULL)
		{
			tmp->next = l1;
			return head;
		}
		if (l1->val <= l2->val)
		{
			tmp->next = l1;
			tmp = tmp->next;
			l1 = l1->next;
		}
		else if (l1->val > l2->val)
		{
			tmp->next = l2;
			tmp = tmp->next;
			l2 = l2->next;
		}
	}
	return head;
}
