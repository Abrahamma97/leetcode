int lengthOfLIS(int* nums, int numsSize) {
    int *arr = (int *)calloc(numsSize, sizeof(int));
    int max = 0, mid;

    for(int k = 0; k < numsSize; k++) {
       int i = 0;
        int j = max;
        while(i < j) {
            mid = (int)(i+j)/2;
            if(nums[k] > arr[mid]) {
                i = mid+1;
            } else {
                j = mid;
            }
        }
        arr[i] = nums[k]; 
        if(i==max) {
            max++;
        }
    
    
    }
    return max;
}
