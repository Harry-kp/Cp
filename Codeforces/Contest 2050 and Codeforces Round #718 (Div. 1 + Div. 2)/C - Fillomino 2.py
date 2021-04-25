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


n = ii()

inp = li()
ans = [[0 for j in range(n)] for i in range(n)]

for i in range(n):
    val = inp[i]
    r = i
    c = i
    ans[r][c] = val
    for j in range(1, val):
        if c-1 >= 0 and ans[r][c-1] == 0:
            c = c-1
        else:
            r = r+1

        ans[r][c] = val

for i in range(n):
    print(*ans[i][:i+1])
