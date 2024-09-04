bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if(matrixSize == 0 || *matrixColSize == 0) {
        return false;
    }
    int rc = *matrixColSize -1, r = 0, lc = 0;
    while(target > matrix[r][rc]) {
        if(r+1 == matrixSize || target <= matrix[r][rc]) {
            if(r+1 == matrixSize ) {
                return false;
            }
            break;
        }
        r++;
    }
    printf("The value of r = %d \n", r);
    while(lc <= rc) {
        int mid = lc + (rc-lc)/2;
        if(matrix[r][mid] > target) {
            rc = mid -1;
        } else if(matrix[r][mid] < target) {
            lc = mid +1;
        } else {
            return true;
        }
    }

    return false;
}
