class Solution:
    def frequencySort(self, s: str) -> str:
        x = Counter(s)
        l1 = sorted(s)
        l1.sort(key=lambda c:x[c], reverse = 1)
        return ''.join(l1)