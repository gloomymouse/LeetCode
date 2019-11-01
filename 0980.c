void GetPath(int** grid, int row_size, int col_size, int x, int y, int empty_num, int walk_num, int* path_num) {
    if (grid[x][y] == 2 && walk_num == empty_num + 1) {
        (*path_num)++;
    } else if (grid[x][y] != 2){
        grid[x][y] = -1;
        if (x > 0 && grid[x-1][y] % 2 == 0) {
            GetPath(grid, row_size, col_size, x-1, y, empty_num, walk_num+1, path_num);
        }
        if (x < row_size - 1 && grid[x+1][y] % 2 == 0) {
            GetPath(grid, row_size, col_size, x+1, y, empty_num, walk_num+1, path_num);
        }
        if (y > 0 && grid[x][y-1] % 2 == 0) {
            GetPath(grid, row_size, col_size, x, y-1, empty_num, walk_num+1, path_num);
        }
        if (y < col_size - 1 && grid[x][y+1] % 2 == 0) {
            GetPath(grid, row_size, col_size, x, y+1, empty_num, walk_num+1, path_num);
        }
        grid[x][y] = 0;
    }
    return;
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize){
    int path_num = 0;
    int empty_num = 0;
    int x, y;
    int col_size = gridColSize[0];
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < col_size; j++) {
            if (grid[i][j] == 0) {
                empty_num++;
            }
            if (grid[i][j] == 1) {
                x = i;
                y = j;
            }
        }
    }
    GetPath(grid, gridSize, col_size, x, y, empty_num, 0, &path_num);
    return path_num;
}
