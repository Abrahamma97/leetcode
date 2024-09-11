/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i = 0, j = numbersSize-1;
    while(i < j) {
        int sum = numbers[i] + numbers[j];
        if(sum > target) {
            j--;
        } else if(sum < target) {
            i++;
        } else {
            int *res = (int *)malloc(sizeof(int)*2);
            res[0] = i+1;
            res[1] = j+1;
            returnSize[0] = 2;
            return res;
        }
    }

            return 0;

}
