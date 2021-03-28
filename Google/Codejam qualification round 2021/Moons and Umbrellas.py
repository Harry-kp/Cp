from sys import stdin,stdout
import math
# from itertools import permutations
# from collections import deque,Counter,OrderedDict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# import heapq
# from functools import reduce
def ii():return int(stdin.readline())
def mi():return map(int,stdin.readline().split())
def li():return list(mi())
def si():return stdin.readline()

tt = ii()
for t in range(tt):
    x,y,s = input().split()
    x = int(x)
    y = int(y)
    
    n = len(s)
    
    dp = []
    for i in range(n):
        dp.append([0,0])
    
    if s[0] == 'C':
        dp[0][1] = math.inf
    elif s[0] == 'J':
        dp[0][0] = math.inf
    
    
    for i in range(1,n):
        if s[i] == 'C':
            dp[i][1] = math.inf
            dp[i][0] = min(dp[i-1][0],dp[i-1][1] + y)
        elif s[i] == 'J':
            dp[i][0] = math.inf
            dp[i][1] = min(dp[i-1][1],dp[i-1][0] + x)
        else:
            dp[i][0] = min(dp[i-1][0],dp[i-1][1] + y)
            dp[i][1] = min(dp[i-1][1],dp[i-1][0] + x)
    
    print("CASE #{}: {}".format(t+1,min(dp[n-1][1],dp[n-1][0])))
    