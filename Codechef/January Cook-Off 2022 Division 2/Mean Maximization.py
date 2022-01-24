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
    n = ii()
    
    l1 = li()

    m1 = max(l1)
    sum1 = sum(l1)

    print(m1 + (sum1-m1)/(n-1))
    
