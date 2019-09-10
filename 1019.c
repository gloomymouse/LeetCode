/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextLargerNodes(struct ListNode* head, int* returnSize){
    struct ListNode* node = head;
    int* ans = (int*)malloc(sizeof(int)*10000);
    int size = 0;
    while (node != NULL) {
        int val = 0;
        struct ListNode* next = node->next;
        while (next != NULL) {
            if (next->val > node->val) {
                val = next->val;
                break;
            }
            next = next->next;
        }
        ans[size++] = val;
        node = node->next;
    }
    *returnSize = size;
    return ans;
}
