from sys import stdin, stdout
import math
# from collections import deque,Counter,OrderedDict
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


t = ii()
for _ in range(t):
    n = ii()
    if n == 1:
        print(1)
    elif n == 2:
        print(-1)
    else:
        c = 1
        ans = []
        for i in range(0, n):
            tmp = []
            for j in range(0, n):
                tmp.append(c)
                c += 1
            ans.append(tmp)

        for i in range(0, n, 2):
            last = ans[-1][i]
            prev = ans[0][i]
            for j in range(1, n):
                ans[j][i], prev = prev, ans[j][i]
            ans[0][i] = last

        for i in ans:
            print(*i)
