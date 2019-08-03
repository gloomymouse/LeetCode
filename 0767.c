typedef struct CharCnt {
    char c;
    int cnt;
} CharCnt;

int comp(const void* a, const void* b) {
    return ((CharCnt*)b)->cnt - ((CharCnt*)a)->cnt;
}

char * reorganizeString(char * S){
    /* 按字母出现的次数重新排序S */
    int len = strlen(S);
    CharCnt chars[26];
    for (int i = 0; i < 26; i++) {
        chars[i].c = 'a' + i;
        chars[i].cnt = 0;
    }
    for (int i = 0; i < len; i++) {
        chars[S[i]-'a'].cnt++;
    }
    qsort(chars, 26, sizeof(CharCnt), comp);
    int n = 0;
    for (int i = 0; i < 26; i++) {
        if (chars[i].cnt == 0) {
            break;
        }
        for (int j = 0; j < chars[i].cnt; j++) {
            S[n++] = chars[i].c;
        }
    }
    
    /* 隔空插入字符 */
    char* ans = (char*)malloc(len+1);    
    n = 0;
    for (int i = 0; i < len; i++) {
        if (n >= len) {
            n = 1;
        }
        ans[n] = S[i];
        n += 2;
    }
    
    /* 检查是否重复 */
    for (int i = 0; i < len; i++) {
        if (ans[i] == ans[i+1]) {
            free(ans);
            return "";
        }
    }
    ans[len] = '\0';
    return ans;
}
