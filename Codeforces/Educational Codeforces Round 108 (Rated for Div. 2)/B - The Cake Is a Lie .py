import math
from sys import stdin, stdout
import sys
sys.setrecursionlimit(1000000)
# from collections import deque,Counter,OrderedDict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# import heapq
# from functools import reduce


def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()


dict1 = {}


def solve(i, j, k, n, m):
    if (i, j, k) in dict1:
        return dict1[(i, j, k)]
    if(i > n or j > m):
        return False
    if(i == n and j == m and k == 0):
        return True
    if(k == 0):
        return False

    dict1[(i, j, k)] = solve(i+1, j, k-j, n, m) or solve(i, j+1, k-i, n, m)

    return dict1[(i, j, k)]


for _ in range(ii()):
    n, m, k = mi()

    if solve(1, 1, k, n, m):
        print('YES')
    else:
        print('No')
    dict1.clear()
