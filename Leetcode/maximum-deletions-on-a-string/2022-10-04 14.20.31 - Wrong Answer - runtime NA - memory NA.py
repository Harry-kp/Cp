class Solution:
    def deleteString(self, s: str) -> int:
        cur = ""
        c = 0
        for i in range(len(s)):
            cur+=s[i]
            if s[i+1:].startswith(cur):
                c+=1
                cur = ""
            print(cur)
        print(c)
        return c+1
                