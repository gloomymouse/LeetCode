void GetNum(char** board, int* xnum, int* onum) {
    if (board == NULL || xnum == NULL || onum == NULL) {
        return;
    }
    int x = 0;
    int o = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                x++;
            } else if (board[i][j] == 'O') {
                o++;
            }
        }
    }
    *xnum = x;
    *onum = o;
    return;
}

void CheckWin(char** board, int* xwin_num, int* owin_num) {
    if (board == NULL || xwin_num == NULL || owin_num == NULL) {
        return;
    }
    int x = 0;
    int o = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            if (board[i][0] == 'X') {
                x++;
            } else if ( board[i][0] == 'O') {
                o++;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            if (board[0][i] == 'X') {
                x++;
            } else if (board[0][i] == 'O') {
                o++;
            }
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        if (board[0][0] == 'X') {
            x++;
        } else if (board[0][0] == 'O') {
            o++;
        }
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        if (board[0][2] == 'X') {
            x++;
        } else if (board[0][2] == 'O') {
            o++;
        }
    }
    *xwin_num = x;
    *owin_num = o;
    return;
}

bool validTicTacToe(char ** board, int boardSize){
    int xnum = 0;
    int onum = 0;
    int xwin_num = 0;
    int owin_num = 0;
    GetNum(board, &xnum, &onum);
    CheckWin(board, &xwin_num, &owin_num);
    if (xnum < onum || xnum > onum + 1) {
        return false;
    }
    if (xwin_num > 2 || owin_num > 2
        || (xwin_num > 0 && owin_num > 0)) {
        return false;
    }
    if (xnum == onum && xwin_num > 0) {
        return false;
    }
    if (xnum > onum && owin_num > 0) {
        return false;
    }
    return true;
}
