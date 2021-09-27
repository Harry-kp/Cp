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
    A = li()
    B = li()
    x1 = y1 = 0
    for i in range(n):
        x1 += (i+1)*A[i]
        y1 += (i+1)*B[i]
    
    print(y1-x1)
