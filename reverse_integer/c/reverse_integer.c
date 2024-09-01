int reverse(int x){
        int res = 0, d;
        while(x) {
            d = x%10;
            if((res > (INT_MAX/10)) || (res < (INT_MIN/10)) || ((res == (INT_MAX/10)) && (d > (INT_MAX%10))) || ((res == (INT_MIN/10)) && (d < (INT_MIN%10)))) {
                
                return 0;
            } 
            res = res*10;
            res += d;
            x = x/10; 
                        printf("%d\n", res);

        }
        return res;
}
