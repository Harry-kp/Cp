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
    n,p,x,y = mi()
    l1 = li()

    ans = 0
    for i in range(p):
        if(l1[i] == 0):
            ans+=(x)
        else:
            ans+=y
    print(ans)
