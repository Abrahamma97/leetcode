class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        buy = prices[0]

        for p in prices:
            profit = max(profit, p-buy)
            buy = min(p, buy)
        return profit
