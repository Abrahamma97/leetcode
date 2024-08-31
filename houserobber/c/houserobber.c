int max (int a, int b) {
    return (a>b?a:b);
}
int looot(int i, int num, int arr[], int nums[]) {
    int loot = 0;
    if(i >= num) {
        return loot;
    }
    if(arr[i] >= 0) {
        return arr[i];
    } 
    loot = nums[i] + max(looot(i+2,num,arr, nums), looot(i+3,num,arr, nums) );
    arr[i] = loot;
    return arr[i];
}

int rob(int* nums, int numsSize) {
    int loot = 0;
    int arr[1000];
    for(int i = 0; i < 1000; i++) {
        arr[i] = -1;
    }
    loot = max(looot(0,numsSize,arr,nums), looot(1,numsSize,arr, nums) );
    return loot;
}
