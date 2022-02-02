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
    n,k = mi()

    if n>1 and k==1:
        print(-1)
    else:
        for i in range(1,k):
            print(i,end=' ')
        for i in range(n,k-1,-1):
            print(i,end=' ')
        print('')
        
        
