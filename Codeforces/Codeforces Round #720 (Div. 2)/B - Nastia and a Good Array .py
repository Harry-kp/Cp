from sys import stdin, stdout
import math
# from collections import deque,Counter,OrderedDict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# import heapq
# from functools import reduce


def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()


t = 1
t = ii()
mod = 10**9+7
for _ in range(t):
    n = ii()
    l1 = li()

    min1 = min(l1)
    ind = l1.index(min1)

    j = ind-1
    k = ind+1

    c1 = 0
    c2 = 0
    print(n-1)
    while j >= 0:
        if c1 % 2 == 0:
            print(ind+1, j+1, l1[ind], mod)
            l1[j] = mod
        else:
            print(ind+1, j+1, l1[ind], l1[ind])
            l1[j] = l1[ind]
        c1 += 1
        j -= 1

    while k < n:
        if c2 % 2 == 0:
            print(ind+1, k+1, l1[ind], mod)
            l1[k] = mod
        else:
            print(ind+1, k+1, l1[ind], l1[ind])
            l1[k] = l1[ind]
        c2 += 1
        k += 1
