class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        return len(set(sentence.upper())) == 26
        