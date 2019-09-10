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
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize){
    int len = 0;
    struct ListNode* node = root;
    while (node != NULL) {
        len++;
        node = node->next;
    }

    int small_size = len / k;
    int big_num = len - (small_size * k);

    node = root;
    struct ListNode* prev = NULL;
    int big_cnt = 0;
    struct ListNode** ans = (struct ListNode**)malloc(sizeof(struct ListNode*)*k);
    for (int i = 0; i < k; i++) {
        ans[i] = (struct ListNode*)malloc(sizeof(struct ListNode));
        ans[i] = node;
        int size = small_size;
        if (big_cnt < big_num) {
            size++;
            big_cnt++;
        }
        int j = 0;
        while (j < size) {
            prev = node;
            node = node->next;
            j++;
        }
        if (node != NULL) {
            prev->next = NULL;
        }
    }
    *returnSize = k;
    return ans;
}
