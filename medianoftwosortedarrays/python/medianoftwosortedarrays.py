class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1.extend(nums2)
        nums = sorted(nums1)
        if(len(nums) % 2 == 0): 
            return (nums[((len(nums)//2) -1)] + nums[(len(nums)//2)])/2
            
        else:
            return nums[len(nums)//2]
