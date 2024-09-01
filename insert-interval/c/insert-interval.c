/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int min(int a, int b) {
    return a<b?a:b;
 }
 int max(int a, int b) {
    return a>b?a:b;
 }
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int **res = (int **)malloc(sizeof(int*) * (intervalsSize+1));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (intervalsSize + 1));

    int i = 0, j = 0;
    
    while ((i < intervalsSize) && intervals[i][1] < newInterval[0]) {
        res[j] = (int *)malloc(sizeof(int)*2);
        res[j][0] = intervals[i][0];
        res[j][1] = intervals[i][1];
        (*returnColumnSizes)[j] = 2;
        i++;
        j++;
    }
    while(i < intervalsSize && (intervals[i][0] <= newInterval[1])) {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    res[j] = (int *)malloc(sizeof(int)*2);
        res[j][0] = newInterval[0];
        res[j][1] = newInterval[1];
        (*returnColumnSizes)[j] = 2;
        j++;
    while(i < intervalsSize) {
        res[j] = (int *)malloc(sizeof(int)*2);
        res[j][0] = intervals[i][0];
        res[j][1] = intervals[i][1];
        (*returnColumnSizes)[j] = 2;
        i++;
        j++;
    }
    *returnSize = j;
    return res;
}
