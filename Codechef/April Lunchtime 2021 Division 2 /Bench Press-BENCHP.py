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


for _ in range(ii()):
    n, w, wr = mi()
    l1 = li()

    if wr >= w:
        print('YES')
    else:
        dict1 = defaultdict(int)
        for i in l1:
            dict1[i] += 1

        dict1 = [(x, y) for x, y in sorted(dict1.items())]
        w -= wr
        sum1 = 0
        for i, j in dict1:
            if j % 2 == 0:
                sum1 += (i*j)
            else:
                sum1 += (i*(j-1))

            if sum1 >= w:
                print('YES')
                break
        else:
            print('NO')
