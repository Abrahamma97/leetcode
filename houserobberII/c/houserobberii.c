int max (int a, int b) {
    return a>b? a:b;
}
int loot(int nums[], int start, int end) {
    int prev = 0, next = 0, cur = 0;
    for(int i = start; i < end; i++) {
        next = max(cur, prev+nums[i]);
        prev = cur;
        cur = next;
    }
    return next;
}
int rob(int* nums, int numsSize) {
    if(numsSize == 1) {
        return nums[0];
    }

    int range1 = loot(nums, 0, numsSize-1);
    int range2 = loot(nums, 1, numsSize);

    return range1>range2?range1:range2;
}
