class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        map = defaultdict(int)
        for i in arr:map[i]+=1
        return len(map.values()) == len(set(map.values()))