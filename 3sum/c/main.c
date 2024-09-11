/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int compare(const void* a, const void* b) {
    return (*(int* )a) - (*(int *)b);
 }
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
    int k = 0;
    int **res = (int **)malloc(sizeof(int*)*200000000);
    *returnColumnSizes = (int *)malloc(sizeof(int)*200000000);

    
    qsort(nums, numsSize, sizeof(int), compare);
    
    for(int i = 0; i < numsSize; i++) {
        int l = i+1;
        int r = numsSize -1;
        printf("Hello\n");
        if(i > 0 && nums[i] == nums[i-1]) {
            continue;     
        }
        
        while(l<r) {
            int sum = nums[i] + nums[l] + nums[r];
            printf("%d %d %d \n", nums[i], nums[l], nums[r-1]);
            if(sum == 0) {
               // printf("%d %d %d\n", nums[i], nums[l], nums[r]);
                res[k] = (int *)malloc(sizeof(int)*3); 
                res[k][0] = nums[i];
                res[k][1] = nums[l];
                res[k][2] = nums[r];
                
                (*returnColumnSizes)[k] = 3;
                

                k++;
            }
            if(sum < 0) {
            l++;
            while(nums[l] == nums[l-1] && l < r) {
                l++;
            }
            } else {
            r--;
            while( r < numsSize - 1 && nums[r] == nums[r+1] && l < r) {
                r--;
            }
            }
        }
    }
    *returnSize = k;
    return res;
}
