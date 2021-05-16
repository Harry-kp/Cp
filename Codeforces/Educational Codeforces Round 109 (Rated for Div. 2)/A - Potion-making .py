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


def solve(k):
    for i in range(0, 101):
        for j in range(0, 101):
            if i or j:
                if (i * 100)/(i+j) == k:
                    # print(i,j)
                    return i+j


t = 1
t = ii()
# mod = 10**9+7
for _ in range(t):
    k = ii()
    print(solve(k))
