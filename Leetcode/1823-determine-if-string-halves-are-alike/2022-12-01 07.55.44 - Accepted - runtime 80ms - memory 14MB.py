class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vow = ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
        l1 = s[0:len(s)//2]
        l2 = s[len(s)//2:]
        return len(''.join(i for i in l1 if i in vow)) == len(''.join(i for i in l2 if i in vow))