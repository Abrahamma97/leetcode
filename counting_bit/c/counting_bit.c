/**
 * Note: The returned array must be malloced, assume caller calls free().
 
0 = 0
1 = 01
2 = 10
3 = 11
4 = 101
5 = 110
6 = 111
    */
int* countBits(int n, int* returnSize) {
   int* ans = (int *)malloc(sizeof(int)*(n+1));
   ans[0] = 0;
   for(int i = 1; i <= n; i++) {
    ans[i] = ans[i >> 1] + (i&1);
   }
   *returnSize = n+1;
   return ans;
}
