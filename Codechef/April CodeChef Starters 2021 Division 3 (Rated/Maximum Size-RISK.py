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

c = 0
def solve(mat, i, j, n, m):
    if i >= 0 and i < n and j >= 0 and j < m and mat[i][j]:
        mat[i][j] = 0
        global c
        c += 1

        solve(mat, i+1, j, n, m)
        solve(mat, i-1, j, n, m)
        solve(mat, i, j+1, n, m)
        solve(mat, i, j-1, n, m)


for _ in range(ii()):
    n, m = mi()
    mat = []
    for i in range(n):
        mat.append([int(x) for x in list(input())])

    ans = []
    for i in range(n):
        for j in range(m):
            c = 0
            if mat[i][j]:
                solve(mat, i, j, n, m)
                ans.append(c)

    out = 0
    ans.sort(reverse=True)
    for i in range(1, len(ans), 2):
        out += ans[i]
    print(out)
