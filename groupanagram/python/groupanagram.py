class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map = {}
        list1 = []
        for s in strs:
            if(''.join(sorted(s)) not in map):
                map[''.join(sorted(s))] = [''.join(s)]
            else:
                map[''.join(sorted(s))].append(''.join(s))
        for i in map.values():
            list1.append(i)
        return list1
