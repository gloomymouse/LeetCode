int divide(int dividend, int divisor){
    if (-2147483648 == dividend && divisor == -1) {
        return 2147483647;
    }
    int neg = (dividend > 0) ^ (divisor > 0);
    long dvd = (dividend >= 0) ? (long)dividend : (-(long)dividend);
    long dvs = (divisor >= 0) ? (long)divisor : (-(long)divisor);
    
    long bit = 0;
    for (; bit < 64; bit++) {
        if (dvd <= (dvs << bit)) {
            break;
        }
    }
    
    long quo = 0;
    for (; bit >= 0; bit--) {
        if (dvd < (dvs << bit)) {
            continue;
        }
        quo |= (long)((long)1 << bit);
        dvd -= (dvs << bit);
    }
    
    if (neg == 1) {
        return (int)-quo;
    }
    return (int)quo;
}
