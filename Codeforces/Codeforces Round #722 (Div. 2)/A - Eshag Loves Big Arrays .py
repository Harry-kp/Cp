from sys import stdin
# import math
# import heapq
# from collections import deque,Counter,defaultdict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# from functools import reduce

import math
def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()


t = 1
t = ii()
for _ in range(t):
    n = ii()
    l1 = li()

    min1 = min(l1)
    c = 0
    for i in l1:
        if i > min1:
            c += 1
    print(c)
