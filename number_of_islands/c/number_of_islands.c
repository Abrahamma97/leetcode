int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int row, int col, int rowmax, int colmax, char **grid) {
    if((row >= 0) && (row < rowmax) && (col >= 0) && (col < colmax) && (grid[row][col] == '1')) {
        grid[row][col] = '0';
        for(int i = 0; i < 4; i++) {
            dfs((row + dir[i][0]), (col+dir[i][1]), rowmax, colmax, grid);  
        }
    }
}




int numIslands(char** grid, int gridSize, int* gridColSize) {
    int island = 0;
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < *gridColSize; j++) {
            if(grid[i][j] == '1') {
                dfs(i, j, gridSize, *gridColSize, grid);
                island++;
            }
        }
    }
    return island;
}
