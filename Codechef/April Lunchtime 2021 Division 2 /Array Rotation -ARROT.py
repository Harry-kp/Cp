from sys import stdin, stdout
import math
from collections import deque, Counter, OrderedDict, defaultdict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# import heapq
# from functools import reduce


def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()


mod = 1000000007

n = ii()
l1 = li()
sum1 = sum(l1)

q = ii()

for i in li():
    sum1 = (2*sum1) % mod
    print(sum1)
