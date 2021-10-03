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
import math
def solve(a,b,h):
    if(a>=h or b>=h):return 1
    if(h%(a+b) == 0):
        return 2*h//(a+b)
    
    tmp = math.floor(h//(a+b))
    cnt = tmp*(a+b)
    # print(cnt,tmp)
    if(h-cnt<= a or h-cnt<=b):
        return 2*tmp+1
    return 2*tmp+2

t = 1
t = ii()
for _ in range(t):
    n,h = mi()
    l1 = li()
    l1.sort()
    print(solve(l1[-1], l1[-2], h))

