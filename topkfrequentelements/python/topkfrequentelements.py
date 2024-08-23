class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)

        k = heapq.nlargest(k, count.items(), key=lambda x: x[1])
        return [i for i,j in k]
        
