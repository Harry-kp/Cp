class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        x = Counter(word1)
        for i in word2:
            if i in x:
                x[i]-=1
            else:
                x[i] = 1
        
        return sum(x.values()) == 0