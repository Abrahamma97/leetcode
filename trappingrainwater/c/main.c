int max(int a, int b) {
    return a>=b?a:b;
}
int min(int a, int b) {
    return a<=b?a:b;
}
int trap(int* height, int heightSize) {
    int contain = 0, mr = 0, ml = 0, sum = 0;
    int *maxright = (int *)malloc(sizeof(int) *heightSize);
    int *maxleft = (int *)malloc(sizeof(int) *heightSize);
    int i;
    for(i = 0; i < heightSize; i++) {
        maxleft[i] = ml;
        ml = max(height[i], ml);
    }
    for(i = heightSize -1; i >= 0; i-- ) {
        maxright[i] = mr;
        mr = max(height[i], mr);
    }
  
    for(i = 0; i < heightSize; i++) {
        sum = min(maxleft[i], maxright[i]) - height[i];
        
        if(sum > 0) {
            contain += sum;
        }
    }
    return contain;

    
}
