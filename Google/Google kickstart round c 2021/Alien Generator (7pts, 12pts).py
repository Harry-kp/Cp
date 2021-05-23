from sys import stdin, stdout
import math
# from collections import deque,Counter,OrderedDict
# from collections import defaultdict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# import heapq
# from functools import reduce


def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()


def solve(n, g):
    if ((2*g - n*n + n) % (2*n) == 0):
        return True
    return False


def max_val(g):
    tmp = math.sqrt(1+4*2*g)
    tmp = tmp-1
    tmp = int(tmp//2)+1
    return tmp


t = 1
t = ii()

for _ in range(t):
    g = ii()
    c = 0
    max1 = max_val(g)
    for i in range(1, max1):
        if solve(i, g):
            c += 1
    print(f'Case #{_+1}: {c}')
