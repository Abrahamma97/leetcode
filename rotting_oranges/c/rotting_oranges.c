
typedef struct {
    int row;
    int col;
} pair;
int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int dir[][2] =  {{0,1},{0,-1},{1,0},{-1,0}};
    int timestamp = 0, front = 0, rear = 0, size = 0;
    int rowmax = gridSize;
    int colmax = *gridColSize;
    int isfresh = 0;
    pair queue[1000];


    for(int r = 0; r < rowmax; r++) {
        for(int c = 0; c < colmax; c++) {
            if(grid[r][c] == 2) {
                queue[rear++] = (pair){r,c};
            } else if(grid[r][c] == 1) {
                isfresh = 1;
            }
        }
    }

    if(!isfresh) {
        return 0;
    }

    while(front < rear) {
        size = rear - front;
        for(int i = 0; i < size; i++) {
            pair p = queue[front++];
            
            for(int j = 0; j < 4; j++) {
                int r = p.row  + dir[j][0];
                int c = p.col + dir[j][1];

                if(r >= 0 && c >= 0 && r < rowmax && c < colmax && grid[r][c] == 1) {
                    grid[r][c] = 2;
                    queue[rear++] = (pair){r,c};
                    isfresh = 1; 
                }

            }
        }
        if(isfresh) {
        timestamp++;
        isfresh = 0;
        }
    }
    for(int r = 0; r < rowmax; r++) {
        for(int c = 0; c < colmax; c++) {
            if(grid[r][c] == 1) {
                return -1;
            }
        }
    }
    return timestamp;
}
