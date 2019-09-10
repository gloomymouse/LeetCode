/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int numComponents(struct ListNode* head, int* G, int GSize){
    char num[10000];
    memset(num, 0, 10000);
    for (int i = 0; i < GSize; i++) {
        num[G[i]] = 1;
    }
    int ans = 0;
    int flag = 0;
    struct ListNode* node = head;
    while (node != NULL) {
        if (num[node->val] == 1) {
            if (flag == 0) {
                flag = 1;
                ans++;
            }
        } else {
            if (flag == 1) {
                flag = 0;
            }
        }
        node = node->next;
    }
    return ans;
}
