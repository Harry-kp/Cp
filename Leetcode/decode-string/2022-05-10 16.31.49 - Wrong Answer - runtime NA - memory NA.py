class Solution:
    def decodeString(self, s: str) -> str:
        ans = ''
        
        i = 0
        n = len(s)
        while i<n:
            if s[i].isdigit():
                val = int(s[i])
                i+=1
                while i<n and s[i].isdigit():
                    val = val*10+int(s[i])
                    i+=1
                i+=1
                p = ''
                while i<n and s[i].islower():
                    p+=s[i]
                    i+=1
                i+=1
                ans+=(p*val)
            else:
                p+=s[i]
                i+=1
            
        return ans
        