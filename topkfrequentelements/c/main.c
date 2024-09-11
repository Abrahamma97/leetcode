/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct  node {
    int val;
    int count;
} heap;
 int compare(const void *a, const void *b) {
    return ((heap*)b)->count - ((heap*)a)->count;
 }
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
    int hashmap[1000001] = {0};
    int m = 0;
    for (int i = 0; i < numsSize; i++) {
        hashmap[10000+nums[i]]++;  
        m++;
    } 
    heap* h = (heap *)malloc(sizeof(heap)*m);
    m = 0;
    for(int i = 0; i < numsSize; i++) {
        if(hashmap[10000+nums[i]] > 0) {
            h[m].val = nums[i];
            h[m].count = hashmap[10000+nums[i]];
            hashmap[10000+nums[i]] = 0;
                        m++;

        }
        
    }
    qsort(h, m, sizeof(heap), compare);
    int* result = (int*) malloc(sizeof(int)*k);
    for(int i = 0; i < k; i++) {
        result[i] = h[i].val;
    }
    *returnSize = k;

    return result;
}
