class Solution:
   
    def jobScheduling(self, s: List[int], e: List[int], p: List[int]) -> int:
        jobs,n = sorted(zip(s,e,p)),len(s)
        cache = {}
        def dfs(i):

            if i in cache:
                return cache[i]
            if i>=len(jobs):return 0

            k = bisect_left(jobs, jobs[i][1], key=lambda x:x[0])
            cache[i] = max(dfs(i+1), jobs[i][2]+dfs(k))
            return cache[i]

        return dfs(0)
        

