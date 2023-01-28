class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        word1+=word2
        x = Counter(word1)

        tmp = 0
        for i in x:
            if x[i]%2:
                tmp+=1
        return tmp%2 == 0




