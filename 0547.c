void CheckFriend(int** M, int MSize, char* visit, int pos) {
    visit[pos] = 1;
    for (int i = 0; i < MSize; i++) {
        if (visit[i] == 1) {
            continue;
        }
        if (M[pos][i] == 0) {
            continue;
        }
        CheckFriend(M, MSize, visit, i);
    }
    return;
}

int findCircleNum(int** M, int MSize, int* MColSize){
    char visit[200];
    memset(visit, 0, 200);
    int circle_num = 0;
    for (int i = 0; i < MSize; i++) {
        if (visit[i] == 0) {
            CheckFriend(M, MSize, visit, i);
            circle_num++;
        }
    }
    return circle_num;
}
