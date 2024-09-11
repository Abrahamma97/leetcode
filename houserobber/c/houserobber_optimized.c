int loot(int *nums, int start, int end) {
    int cur = 0, prev = 0, next = 0;
    for(int i = start; i < end; i++) {
        next = cur > (prev + nums[i]) ? cur: (prev+nums[i]);
        prev = cur;
        cur = next;
    }
    return next;
}
int rob(int* nums, int numsSize) {
    if(numsSize == 1) {
        return nums[0];
    }
    return loot(nums, 0 ,numsSize);
}
