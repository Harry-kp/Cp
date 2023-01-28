class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        x,y = Counter(word1),Counter(word2)

        return x.keys() == y.keys() and sorted(x.values()) == sorted(y.values())