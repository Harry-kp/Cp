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

for _ in range(t):
    a, b = mi()
    if b == 1:
        print('NO')
    else:
        print('YES')
        print(a*b-a, a*b+a, 2*a*b)
