class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        a = []
        nums.sort()
        for i,j in enumerate(nums):
            
            if i > 0 and j == nums[i - 1]:
                continue
            l,r = i+1, len(nums)-1
            while(l<r):
                sum = j + nums[l] + nums[r]
                if(sum > 0):
                    r = r-1
                elif(sum < 0):
                    l = l+1
                else:
                    a.append([j,nums[l],nums[r]])
                    l = l+1
                    r = r-1
                    while(nums[l] == nums[l-1] and l < r):
                        l = l+1

        return (a)
        
