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


def prefix(l1):
    for i in range(1, len(l1)):
        l1[i] += l1[i-1]


for _ in range(ii()):
    n = ii()
    dict1 = {}

    l1 = li()
    l2 = li()
    for i in range(n):
        if l1[i] in dict1:
            dict1[l1[i]].append(l2[i])
        else:
            dict1[l1[i]] = [l2[i]]
    for i in dict1:
        dict1[i].sort(reverse=True)

    for i in dict1:
        prefix(dict1[i])
    # print(dict1)
    ans = [0]*n
    for i in dict1:
        k = len(dict1[i])
        for j in range(1, k+1):
            ind = k - (k % j) - 1
            ans[j-1] += dict1[i][ind]
    print(*ans)
