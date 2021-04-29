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


for _ in range(ii()):
    r, b, d = mi()
    if r > b:
        r, b = b, r
    tmp = b//r-1
    if b % r != 0:
        tmp += 1
    if tmp <= d:
        print('YES')
    else:
        print('NO')
