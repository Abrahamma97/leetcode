//1st Method

int count(int i, int n, int arr[]) {
    if(i > n) {
        return 0;
    } else if(i == n) {
        return 1;
    }
    if(arr[i+1] == 0) {
        arr[i+1] = count(i+1, n, arr);
    }
    if(arr[i+2] == 0) {
        arr[i+2] = count(i+2, n, arr);
    }
    return arr[i+1] + arr[i+2];
}
int climbStairs(int n) {
    int i = 0;
    int arr[100] = {0};
    return (count(0, n, arr)); 
}
