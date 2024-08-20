class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ls = []
        max_length = 0
        for i in s:
            if(i not in ls):
                ls.append(i)

                if(max_length < len(ls)):
                    max_length = len(ls)
            else:
                          
                while (i in ls):
                    ls.pop(0)
                ls.append(i)
        return max_length
