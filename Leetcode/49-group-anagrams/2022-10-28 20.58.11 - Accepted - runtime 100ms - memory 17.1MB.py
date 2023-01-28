class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dict1 = {}
        for i in strs:
            new_str = ''.join(sorted(list(i)))
            if new_str in dict1:
                dict1[new_str].append(i)
            else:
                dict1[new_str] = [i]
        
        ans = []
        for i in dict1:
            ans.append(dict1[i])
        return ans            
        