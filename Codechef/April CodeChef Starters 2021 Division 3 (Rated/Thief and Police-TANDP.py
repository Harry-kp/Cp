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
    n, m = mi()
    x, y = mi()
    a, b = mi()

    stept = n-x + m-y
    tmp = min(n-a, m-b)
    a += tmp
    b += tmp
    stepp = tmp + n-a + m-b

    if stept <= stepp:
        print('YES')
    else:
        print('NO')
