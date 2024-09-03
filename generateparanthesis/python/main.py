
class Solution:
    
    
    def generateParenthesis(self, n: int) -> List[str]:
        stack = []
        res = []
        def backtrack(openN, closeN, stack):
            if(openN < n):
                stack.append('(')
                backtrack(openN+1, closeN, stack)
                stack.pop()
            if(closeN < openN):
                stack.append(')')
                backtrack(openN, closeN+1, stack)
                stack.pop()
            if(closeN == openN == n):
                res.append(''.join(stack))

        backtrack(0,0,stack)
        return res
        
