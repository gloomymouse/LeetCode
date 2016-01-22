/*
typedef struct ListNode
{
    int val;
    struct ListNode *next;
}
*/
typedef struct ListNode ln;

bool isHappy(int n)
{
    int num = 0;
    int tmp = 0;
    ln *dumphead = (ln*)malloc(sizeof(ln));
    dumphead->val = 0;
    dumphead->next = NULL;
    ln *cur = dumphead;
    while (1)
    {
        tmp = n;
        while (n != 0)
        {
            num += (n % 10) * (n % 10);
            n /= 10;
        }
        if (num == 1)
            return true;
        while (cur->next != NULL)
        {
            if (num == cur->next->val)
                return false;
            cur = cur->next;
        }
        cur->next = (ln*)malloc(sizeof(ln));
        cur->next->val = num;
        cur->next->next = NULL;
        cur = dumphead;
        n = num;
        num = 0;
    }
}
