// use linked lists
// take too much time

typedef struct LinkNode
{
    unsigned int val;
    struct LinkNode *next;
} ln;

int nthUglyNumber(int n)
{
    ln *head = (ln*)malloc(sizeof(ln));
    head->val = 1;
    head->next = NULL;
    ln *cur = head;
    ln *tmp;
    ln *insert;
    
    unsigned int num;
    unsigned int result;
    
    while (n--)
    {
        result = cur->val;
        tmp = cur;
        num = result * 2;
        while (tmp != NULL && tmp->val < num)
        {
            if (tmp->next == NULL || tmp->next->val > num)
            {
                insert = (ln*)malloc(sizeof(ln));
                insert->val = num;
                insert->next = tmp->next;
                tmp->next = insert;
            }
            tmp = tmp->next;
        }
        num = result * 3;
        while (tmp != NULL && tmp->val < num)
        {
            if (tmp->next == NULL || tmp->next->val > num)
            {
                insert = (ln*)malloc(sizeof(ln));
                insert->val = num;
                insert->next = tmp->next;
                tmp->next = insert;
            }
            tmp = tmp->next;
        }
        num = result * 5;
        while (tmp != NULL && tmp->val < num)
        {
            if (tmp->next == NULL || tmp->next->val > num)
            {
                insert = (ln*)malloc(sizeof(ln));
                insert->val = num;
                insert->next = tmp->next;
                tmp->next = insert;
            }
            tmp = tmp->next;
        }
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    return result;
}
