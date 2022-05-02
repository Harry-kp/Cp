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
for _ in range(t):
    x,y = mi()
    c = y
    nc = x-y
    ans = 0
    if c>0:
        ans += 2*c-1
    if nc>0:
        ans+=nc
        if c>0:
            ans+=1
    print(ans)
