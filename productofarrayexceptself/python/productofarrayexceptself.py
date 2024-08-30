class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        pre = nums.copy()
        pos = nums.copy()
        res = [1]*len(nums)


        for i,n in enumerate(pre):
            if(i == 0):
                continue
            pre[i] *= pre[i-1]
        
        for i in range(len(nums)-1,-1,-1):
            if(i == (len(nums)-1)):
                continue
            pos[i] *= pos[i+1]

        for i,j in enumerate(nums):
            if(i != 0):
                res[i] *= pre[i-1]
            if(i!= (len(nums)-1)):
                res[i] *= pos[i+1]
        return res


             

