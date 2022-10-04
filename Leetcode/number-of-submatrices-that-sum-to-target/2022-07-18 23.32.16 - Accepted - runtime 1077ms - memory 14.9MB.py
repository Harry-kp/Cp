class Solution:
    def numSubmatrixSumTarget(self, M: List[List[int]], T: int) -> int:
        xlen, ylen, ans = len(M[0]), len(M), 0
        for r in M:
            for j in range(1, xlen):
                r[j] += r[j-1]
        for j in range(xlen):
            for k in range(j, xlen):
                res, csum = {0: 1}, 0
                for r in M:
                    csum += r[k] - (r[j-1] if j else 0)
                    if csum - T in res: ans += res[csum-T]
                    res[csum] = res[csum] + 1 if csum in res else 1  
        return ans