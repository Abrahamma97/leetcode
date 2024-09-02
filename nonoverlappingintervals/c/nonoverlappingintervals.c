struct Interval {
    int start;
    int end;
};
int compare(const void* a, const void* b) {
    return ((struct Interval*)a)->end - ((struct Interval*)b)->end; 
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    int mergedindex = 0, i = 0, count = 0, end;

    struct Interval* si = (struct Interval*)malloc(sizeof(struct Interval)*intervalsSize);
    for(i = 0; i < intervalsSize; i++) {
        si[i].start = intervals[i][0];
        si[i].end = intervals[i][1];
    }

    qsort(si, intervalsSize, sizeof(struct Interval), compare);
    struct Interval* mergedarray = (struct Interval*)malloc(sizeof(struct Interval)*intervalsSize);
    end = si[0].end;
    for(int i = 1; i < intervalsSize; i++) {
        if(end <= si[i].start) {
            end = si[i].end;
        } else {
            count++;
        }
    }
    return count;
}
