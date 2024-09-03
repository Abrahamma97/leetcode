class Solution:
    
    def compare (i, j):
        if((i=='{' and j == '}') or (i=='(' and j == ')') or (i=='[' and j == ']')):
            return True
        else: 
            return False

    def isValid(self, s: str) -> bool:
        stack = []
        for i in s:
            if (i == '(' or i == '{' or i == '['):
                stack.append(i)
            else:

                if(not stack):
                    return False
                if((not Solution.compare(stack.pop(), i))):
                    return False
        if(stack == []):
            return True
        else:
            return False

        
