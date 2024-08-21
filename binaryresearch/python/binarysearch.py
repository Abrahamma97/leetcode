class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l,r = 0,(len(nums)-1)

        while(l <= r):
            i = l + ((r-l)//2)
            n = nums[i]
            if(target > n):
                l = i+1
            elif(target < n):
                r = i-1
            else:
                return i
        return -1
