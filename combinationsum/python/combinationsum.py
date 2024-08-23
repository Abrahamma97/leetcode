class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []

        def dfs(i,s,total):
            print(s,total)
            if(target == total):
                res.append(s.copy())
                return res
            elif(i >= len(candidates) or total > target):
                return res
            else:
                s.append(candidates[i])
                dfs(i,s,total+candidates[i])
                s.pop()
                dfs(i+1,s,total)
        dfs(0,[],0)
        return res
        
