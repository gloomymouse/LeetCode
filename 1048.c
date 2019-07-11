int isPre(char* p, char* s) {
    int n = 0;
    int i = 0; 
    int j = 0; 
    int pl = strlen(p);
    int sl = strlen(s);
    if (pl + 1 != sl) {
        return 0;
    }
    
    while (p[i] != '\0') {
        if (p[i] != s[j]) {
            n++;
            j++;
        } else {
            i++;
            j++;
        }
        if (n > 1) {
            return 0;
        }
    }
    
    return 1;
}

int longestStrChain(char ** words, int wordsSize){
    int dp[1000] = {0};
    int max = 0;
    int len = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < wordsSize - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j+1])) {
                char* ch = words[j];
                words[j] = words[j+1];
                words[j+1] = ch;
            }
        }
    }
    
    for (int i = 0; i < wordsSize; i++) {
        len = 1;
        for (int j = 0; j < i; j++) {
            if (1 == isPre(words[j], words[i])) {
                if (len < dp[j] + 1) {
                    len = dp[j] + 1;
                }
            }
        }
        dp[i] = len;
    }
    
    len = 1;
    for (int i = 0; i < wordsSize; i++) {
        if (len < dp[i]) {
            len = dp[i];
        }
    }
    return len;
}
