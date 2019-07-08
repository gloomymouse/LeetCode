int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int in[1000] = {0};
    int out[1000] = {0};
    int n = 0;
    int res = -1;
    for (int i = 0; i < trustSize; i++) {
        in[trust[i][1]-1]++;
        out[trust[i][0]-1]++;
    }
    for (int i = 0; i < N; i++) {
        if (in[i] == N -1 && out[i] == 0) {
            n++;
            res = i + 1;
        }
        if (n > 1) {
            return -1;
        }
    }
    return res;
}
