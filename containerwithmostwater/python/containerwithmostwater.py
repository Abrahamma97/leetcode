class Solution:
    def maxArea(self, height: List[int]) -> int:
        l,r = 0, len(height)-1
        area, max_area = 0,0

        while(l <r):
            if(height[l] <= height[r]):
                area = (r-l)*height[l]
                max_area = max(area,max_area)
                l = l+1
            else:
                area = (r-l)*height[r]
                max_area = max(area,max_area)
                r=r-1
        return max_area

        
