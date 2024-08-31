/*
Solution 1

int min(int a , int b) {
    return (a<b)?a:b;
}
int mincost (int i, int cost[], int costSize, int arr[]) {
    int costmin;
    if(i >= costSize) {
        return 0;
    } 
    if(arr[i] > 0) {
        costmin = arr[i];
    } else {
        costmin = cost[i] + min(mincost(i+1, cost, costSize, arr), mincost(i+2, cost, costSize, arr));
        arr[i] = costmin;
    }
    return costmin;
}

int minCostClimbingStairs(int* cost, int costSize) {
    int i = 0;
    int arr[10001] = {0};
    int costmin = min(mincost(0, cost, costSize,arr), mincost(1,cost,costSize,arr));

    return  costmin;
} */

int min(int a , int b) {
    return a<b?a:b;
}
int minCostClimbingStairs(int* cost, int costSize) {
    int mincost = 0;
    int i;
    for( i = 2; i< costSize; i++) {
        cost[i] = cost[i]+ min(cost[i-1], cost[i-2]);
    }
    return min(cost[i-1], cost[i-2]);
}
