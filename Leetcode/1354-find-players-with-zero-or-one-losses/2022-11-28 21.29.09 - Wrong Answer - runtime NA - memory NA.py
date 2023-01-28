class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        incoming = defaultdict(int)
        set1 = set()
        for i in matches:
            set1.add(i[0])
            incoming[i[1]]+=1
        
        ans = [[],[]]
        for i in incoming:
            if incoming[i] == 1:
                ans[1].append(i)
        
        ans[0] = [i for i in set1 if i not in incoming]
        ans[1].sort()

        return ans