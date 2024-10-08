class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-s for s in stones]
        heapq.heapify(stones)
        while(len(stones) > 1):
            first = heapq.heappop(stones)
            second = heapq.heappop(stones)
            if(first == second):
                continue
            else:
                heapq.heappush(stones, (first - second))
        if stones == []:
            return 0
        return -stones[0]
