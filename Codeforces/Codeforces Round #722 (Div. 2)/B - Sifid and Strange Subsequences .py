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

    cnt = 0
    min1 = 1000000000000
    min1_dif = min1-1

    for i in l1:
        if i <= 0:
            cnt += 1
        else:
            min1 = min(min1, i)
    l1.sort()
    for i in range(1, n):
        if l1[i] > 0:
            break
        else:
            min1_dif = min(min1_dif, abs(l1[i]-l1[i-1]))

    if(min1_dif >= min1):
        cnt += 1

    print(cnt)
