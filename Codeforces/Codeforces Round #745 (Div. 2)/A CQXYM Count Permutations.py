from sys import stdin
# import math
# import heapq
# from collections import deque,Counter,defaultdict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# from functools import reduce


def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()

t = 1
t = ii()
N = 2*10**5+5
ans = [0]*(N)
ans[0] = 1
MOD = (10**9+7)*2

for i in range(1,N):
    ans[i] = (ans[i-1]%MOD * i%MOD)%MOD
for _ in range(t):
    n = ii()
    print(ans[2*n]//2)
