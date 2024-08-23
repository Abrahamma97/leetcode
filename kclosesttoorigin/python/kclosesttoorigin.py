class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        minheap = []
        res = []
        for x,y in points:
            minheap.append([((x**2)+(y**2)), x,y]) 
        heapq.heapify(minheap)
        
        while(k > 0):
            sum,x,y = heapq.heappop(minheap)
            res.append([x,y])
            k = k-1
        return res
        
