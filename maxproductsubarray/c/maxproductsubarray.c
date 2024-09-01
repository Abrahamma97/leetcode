int max(int a, int b) { return a>b? a:b;}
int min (int a, int b) { return a<b?a:b;}
int maxProduct(int* nums, int numsSize) {
    int cmax = 1, cmin = 1, temp = 1, res = nums[0];

    for(int i = 0; i < numsSize; i++) {
        temp = cmax*nums[i];
        cmax = max(max(cmax*nums[i], cmin*nums[i]), nums[i]);
        cmin = min(min(temp, cmin*nums[i]), nums[i]);
        res = max(cmax,res);
    }
    return res;
}
