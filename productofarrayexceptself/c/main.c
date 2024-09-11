/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *larr = (int *)malloc(sizeof(int)*numsSize);
    int *rarr = (int *)malloc(sizeof(int)*numsSize);

    for(int i = 0; i < numsSize; i++) {
        if( i == 0) {
            larr[i] = 1; 
        } else {
            larr[i] = larr[i-1]*nums[i-1];
        }
    }
    for(int i = numsSize-1; i >= 0; i--) {
        if( i == numsSize -1) {
            rarr[i] = 1; 
        } else {
            rarr[i] = rarr[i+1]*nums[i+1];
        }
    }
    int *res = (int *)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    for(int i = 0; i < numsSize; i++) {
        res[i] = larr[i]*rarr[i];
    }
    return res;
}
