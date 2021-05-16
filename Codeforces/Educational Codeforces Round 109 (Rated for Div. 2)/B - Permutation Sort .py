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
# mod = 10**9+7
for _ in range(t):
    n = ii()
    l1 = li()
    max1 = l1.index(n)

    if l1 == list(sorted(l1)):
        print(0)
    elif l1[0] == 1 or l1[n-1] == n:
        print(1)
    elif l1[0] == n and l1[n-1] == 1:
        print(3)
    else:
        print(2)
