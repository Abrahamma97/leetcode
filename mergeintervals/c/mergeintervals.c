/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct Interval {
    int start;
    int end;
};
int min(int a, int b) {
    return a<b?a:b;
}
int max(int a, int b) {
    return a>b?a:b;
}
int compare(const void *a, const void*b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if(intervalsSize <= 1) {
        *returnSize = intervalsSize;
        *returnColumnSizes = intervalsColSize;
        return intervals;
    }
    struct Interval* si = (struct Interval*)malloc(sizeof(struct Interval)*intervalsSize);
    struct Interval* mergestruct = (struct Interval*)malloc(sizeof(struct Interval)*intervalsSize);
    int i = 0, mergecount = 0;


    for(i = 0; i < intervalsSize; i++) {
        si[i].start = intervals[i][0];
        si[i].end = intervals[i][1];
    }
    qsort(si, intervalsSize, sizeof(struct Interval), compare);

    for(i = 0; i < intervalsSize; i++) {
        if(mergecount == 0 || (mergestruct[mergecount-1].end < si[i].start)) {
            mergestruct[mergecount++] = si[i];
        } else {
            mergestruct[mergecount-1].start = min(mergestruct[mergecount-1].start, si[i].start);
            mergestruct[mergecount-1].end = max(mergestruct[mergecount-1].end, si[i].end);  
        }

    }
    int **res = (int **)malloc(sizeof(int *) * intervalsSize);
    *returnSize = mergecount;
    *returnColumnSizes = (int*)malloc(sizeof(int) * mergecount);
    for(i = 0; i < mergecount; i++) {
        res[i] = (int *)malloc(sizeof(int) * 2);
        res[i][0] = mergestruct[i].start;
        res[i][1] = mergestruct[i].end;
        (*returnColumnSizes)[i] = 2;       
    }
    return res;
}
