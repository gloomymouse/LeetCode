/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 题目不允许翻转原链表 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (l1->val == 0) {
        return l2;
    }
    if (l2->val == 0) {
        return l1;
    }

    struct ListNode* r1 = NULL;
    struct ListNode* r2 = NULL;
    struct ListNode* node = NULL;
    int len1 = 0;
    int len2 = 0;

    /* 逆序拷贝l1 */
    node = l1;
    while (node != NULL) {
        struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val = node->val;
        new->next = r1;
        r1 = new;
        node = node->next;
        len1++;
    }

    /* 逆序拷贝l2 */
    node = l2;
    while (node != NULL) {
        struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val = node->val;
        new->next = r2;
        r2 = new;
        node = node->next;
        len2++;
    }

    /* 逆序长链表为r1，短链表为r2，相加 */
    node = (len1 >= len2) ? r1 : r2;
    r2 = (len1 < len2) ? r1 : r2;
    r1 = node;
    node = r2;
    struct ListNode* prev = NULL;
    while (node != NULL) {
        r1->val += node->val;
        if (r1->val > 9) {
            r1->val -= 10;
            if (r1->next != NULL) {
                r1->next->val++;
            } else {
                r1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                r1->next->val = 1;
                r1->next->next = NULL;
            }
        }
        struct ListNode* tmp = r1->next;
        r1->next = prev;
        prev = r1;
        r1 = tmp;
        node = node->next;
    }

    /* 处理剩余长链表，注意进位 */
    while (r1 != NULL) {
        if (r1->val > 9) {
            r1->val -= 10;
            if (r1->next != NULL) {
                r1->next->val++;
            } else {
                r1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                r1->next->val = 1;
                r1->next->next = NULL;
            }
        }
        struct ListNode* tmp = r1->next;
        r1->next = prev;
        prev = r1;
        r1 = tmp;
    }

    /* 释放r2 */
    while (r2 != NULL) {
        node = r2->next;
        free(r2);
        r2 = node;
    }

    return prev;
}
