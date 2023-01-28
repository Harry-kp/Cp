class Solution:
    def frequencySort(self, s: str) -> str:
        x = Counter(s)

        return sorted(s,key=lambda c:x[c], reverse = 1)