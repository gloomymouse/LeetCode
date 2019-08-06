int comp(const void* a, const void* b) {
    char* as = *(char**)a;
    char* bs = *(char**)b;
    char i[24], j[24];
    memset(i, 0, 24);
    memset(j, 0, 24);
    /* 两个字符串按先后顺序分别拼接后，比较拼接的数字大小 */
    sprintf(i, "%s%s", as, bs);
    sprintf(j, "%s%s", bs, as);
    return strcmp(j, i);
}

char * largestNumber(int* nums, int numsSize){
    char** numsChar = (char**)malloc(sizeof(char*)*numsSize);
    for (int i = 0; i < numsSize; i++) {
        numsChar[i] = (char*)malloc(12);
        memset(numsChar[i], 0, 12);
        sprintf(numsChar[i], "%d", nums[i]);
    }
    qsort(numsChar, numsSize, sizeof(char*), comp);
    char* ans = (char*)malloc(1000);
    memset(ans, 0, 1000);
    for (int i = 0; i < numsSize; i++) {
        sprintf(ans, "%s%s", ans, numsChar[i]);
    }
    if (ans[0] == '0') {
        ans[1] = '\0';
    }
    return ans;
}
