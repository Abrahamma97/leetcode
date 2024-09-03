class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        l = []
        if(len(nums) == 0):
            return 0
# using heapify to convert list into heap
        heapq.heapify(nums)
        i = 0
        l = [heappop(nums) for i in range(len(nums))]
        count = 1
        cmax = 1
        for i in range(1,len(l)):
            if(l[i] == (l[i-1]+1)):
                count = count + 1
            elif(l[i] == l[i-1]):
                pass
            else:
                count = 1
            cmax = max(count,cmax)
        return cmax

        
# printing created heap
        

