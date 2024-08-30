int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int row, int col, int rowmax, int colmax, int **grid, int *count) {
    if((row >= 0) && (row < rowmax) && (col >= 0) && (col < colmax) && (grid[row][col] == 1)) {
        grid[row][col] = 0;
        (*count)++;
        for(int i = 0; i < 4; i++) {
            dfs((row + dir[i][0]), (col+dir[i][1]), rowmax, colmax, grid, count);
        }
    }
}


int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int island = 0;
    int maxcount = 0, count = 0;
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < *gridColSize; j++) {
            if(grid[i][j] == 1) {
                dfs(i, j, gridSize, *gridColSize, grid, &count);
                maxcount = (count > maxcount)?count:maxcount;
                count = 0;
            }
        }
    }
    return maxcount;
}
