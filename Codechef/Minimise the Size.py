from sys import stdin
# import math
# import heapq
# from collections import deque,Counter,defaultdict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# from functools import reduce


def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()
# use python for long mathematical calculations

t = 1
t = ii()
for _ in range(t):
    n = ii()
    if n == 0:
        print(2)
        print(1,1)
    else:
        l1 = []
        tmp = 0
        st = 1<<61
        while st:
            if (tmp&st) != (n&st):
                tmp = tmp ^((st<<1)-1)
                l1.append((st << 1)-1)
            st>>=1
        print(len(l1))
        print(*l1)

