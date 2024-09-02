int maxProfit(int* prices, int pricesSize) {
    int minprice, profit = 0;
    minprice = prices[0];
    for(int i = 1; i < pricesSize; i++) {
        if(minprice <= prices[i]) {
            profit = profit > (prices[i] - minprice) ? profit:(prices[i] - minprice);
        } else {
            minprice = prices[i]; 
        }
    }
    return profit;
    
}
