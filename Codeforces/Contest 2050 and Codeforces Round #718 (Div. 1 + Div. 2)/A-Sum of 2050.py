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


def max1(n):
    c = 1
    while c <= n:
        c *= 10
    return c//10


for _ in range(ii()):
    n = ii()
    if n % 2050 != 0:
        print(-1)
    else:
        n = n/2050
        cou = 0
        while n > 0:
            cou += 1
            b = max1(n)
            n -= b
        print(cou)
