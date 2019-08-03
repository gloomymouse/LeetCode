/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(const void* a, const void* b) {
    return ((int*)b)[1] - ((int*)a)[1];
}
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize){
    /* cnts[i][1]是数字cnts[i][0]在barcodes中出现的次数 */
    int cnts[10001][2] = {0};
    for (int i = 0; i < 10001; i++) {
        cnts[i][0] = i;
        cnts[i][1] = 0;
    }
    for (int i = 0; i < barcodesSize; i++) {
        cnts[barcodes[i]][1]++;
    }
    /* 按出现次数大到小排序 */
    qsort(cnts, 10001, sizeof(cnts[0]), comp);
    /* 按隔一个插一个的方式将数字隔开 */
    int* ans = (int*)malloc(sizeof(int)*barcodesSize);
    int n = 0;
    for (int i = 0; i < 10001; i++) {
        if (cnts[i][1] == 0) {
            break;
        }
        for (int j = 0; j < cnts[i][1]; j++) {
            if (n >= barcodesSize) {
                n = 1;
            }
            ans[n] = cnts[i][0];
            n += 2;
        }
    }
    *returnSize = barcodesSize;
    return ans;
}
