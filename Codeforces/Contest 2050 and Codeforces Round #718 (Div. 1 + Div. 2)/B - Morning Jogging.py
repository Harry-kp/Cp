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


for _ in range(ii()):
    A = []
    n, m = mi()
    for i in range(n):
        l1 = li()
        for j in range(m):
            A.append([l1[j], i, j])

    A.sort()
    ans = [[-1 for j in range(m)]for i in range(n)]

    for i in range(m*n):
        v, a, b = A[i]
        if i < m:
            ans[a][i] = v
        else:
            for j in range(m):
                if ans[a][j] == -1:
                    ans[a][j] = v
                    break

    for i in ans:
        print(*i)
