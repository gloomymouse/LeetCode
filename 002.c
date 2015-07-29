/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next = NULL;
	struct ListNode* cur = head;	// cur当前节点，初始cur指向head
	struct ListNode* tmp;

	int unit;
	int decade = 0;

	while (l1 == NULL && l2 == NULL)
		return NULL;

	while (l1 != NULL || l2 != NULL || decade == 1)
	{
		tmp = (struct ListNode*)malloc(sizeof(struct ListNode));	// 开辟新的tmp节点
		tmp->next = NULL;

		if (l1 != NULL && l2 != NULL)
			unit = l1->val + l2->val + decade;
		if (l1 == NULL && l2 == NULL)
			unit = decade;
		else if (l1 == NULL && l2 != NULL)
			unit = l2->val + decade;
		else if (l1 != NULL && l2 == NULL)
			unit = l1->val + decade;
		
		if (unit <= 9)
		{
			tmp->val = unit;
			decade = 0;
		}
		else
		{
			tmp->val = unit%10;
			decade = 1;
		}
		
		if (l1 != NULL)
			l1 = l1->next;
		if (l2 != NULL)
			l2 = l2->next;

		//cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		cur->next = tmp;	// cur的下一节点为tmp
		cur = cur->next;	// cur指向下一节点
	}
	
	//cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	//cur->next = NULL;
	cur = head->next;	// cur指向head的下一节点，ListNode数据从head的下一节点开始
	return cur;
}
