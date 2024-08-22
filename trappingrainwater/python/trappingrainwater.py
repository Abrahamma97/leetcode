class Solution:
    def trap(self, height: List[int]) -> int:
        maxleft = [0]*(len(height))
       # print(maxleft)
        maxright = [0] * (len(height))
        ml = 0
        mr = 0
        for i,j in enumerate(height):
            maxleft[i] = max(ml,maxleft[i])
            ml = max(ml,height[i])
        for i in range((len(height)-1),-1,-1):
            maxright[i] = max(mr,maxright[i])
            mr = max(mr,height[i])
        contain = 0
        for i in range(0,len(height)):
            c = min(maxleft[i],maxright[i]) - height[i]
            if(c > 0):
                contain += c
        return contain
        
