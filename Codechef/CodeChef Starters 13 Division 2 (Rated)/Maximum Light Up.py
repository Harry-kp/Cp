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
    P,a,b,c,x,y = mi()
    A = x*a + b
    C = c + y*a

    ans = 0

    i = 0
    while(i*A<=P):
        ans = max((i + (P-(i*A))//C),ans)
        i+=1
    print(ans)

