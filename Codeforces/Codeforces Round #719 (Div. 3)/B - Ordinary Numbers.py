import bisect
from sys import stdin, stdout
import math
from collections import deque, Counter, OrderedDict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
import heapq
# from functools import reduce


def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()


# ans = []
# for i in range(1,10):
#     ans.append(9*i)

ans = []
for i in range(1, 10):
    i = int('1'*i)
    for j in range(1, 10):
        ans.append(j*i)

# print(len(ans))
t = ii()
for _ in range(t):
    n = ii()
    print(bisect.bisect(ans, n))
