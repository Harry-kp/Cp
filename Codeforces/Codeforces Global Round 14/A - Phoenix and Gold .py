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


for _ in range(ii()):
    n, x = mi()
    l1 = li()
    l1.sort()

    if sum(l1) == x:
        print('NO')
    else:
        print('YES')
        sum1 = 0
        for i in range(n):
            sum1 += l1[i]
            if sum1 == x:
                l1[i], l1[-1] = l1[-1], l1[i]
                break
        print(*l1)
