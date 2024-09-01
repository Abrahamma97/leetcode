int numDecodings(char* s) {
    int len = strlen(s);
    if(len == 1) {
        return (s[0] == '0')?0:1;
    }
    int *dp = (int *)malloc(sizeof(int)*(len+1));
    dp[len] = 1;
    dp[len-1] = s[len-1] == '0'?0:1;

    for(int i = len -2; i >= 0; i--) {
        if(s[i] == '0') {
            dp[i] = 0;
        } else if(s[i] == '1' || s[i] == '2') {
            if(s[i] == '2' && s[i+1] >= '7') {
                dp[i] = dp[i+2];
            } else {
                dp[i] = dp[i+1] + dp[i+2];
            }
        } else {
            dp[i] = dp[i+1];
        }   
    }
    return dp[0];    
}
