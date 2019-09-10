bool isLongPressedName(char * name, char * typed) {
    int n = 0;
    int t = 0;
    while (name[n] != '\0' || typed[t] != '\0') {
        char nc = name[n];
        int nnum = 0;
        while (nc == name[n] && name[n] != '\0') {
            nnum++;
            n++;
        }
        char tc = typed[t];
        int tnum = 0;
        while (tc == typed[t] && typed[t] != '\0') {
            tnum++;
            t++;
        }
        if (nc != tc || nnum > tnum) {
            return false;
        }
    }
    return true;
}
