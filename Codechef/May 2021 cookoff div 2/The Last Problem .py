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


ans = [[0 for i in range(2*1002)]for j in range(2*1002)]

c = 1
for i in range(1, 2*1002):
    a = i
    b = 1

    while b <= i and a > 0:
        ans[b][a] = c
        c += 1
        b += 1
        a -= 1

t = 1
t = ii()
# print(ans[1000][1000],ans[1001][999])
for _ in range(t):
    x1, y1, x2, y2 = mi()

    out = 0

    while x1 <= x2:
        out += ans[x1][y1]
        x1 += 1

    x1 -= 1
    y1 += 1
    while y1 <= y2:
        out += ans[x1][y1]
        y1 += 1

    print(out)

