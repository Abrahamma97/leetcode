class Solution:
    def longestPalindrome(self, s: str) -> str:
        str = list(s)
        s = []
        pal = []
        while(str != []):
            s.extend(str)
            while(s != []):
                if(s == s[::-1]):
                    if(len(s) > len(pal)):
                        pal = ''.join(s)
                s.pop()
            if(str == []):
                break
            str.pop(0)
        return pal

