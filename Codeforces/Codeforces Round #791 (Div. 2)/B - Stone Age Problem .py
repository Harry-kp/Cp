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


t = 1
# t = ii()
for _ in range(t):
    n,q = mi()
    l1 = li()
    prev = 0
    d1 = dict(enumerate(l1))
    sum1 = sum(l1)
    for i in range(q):
        l2 = li()

        if l2[0] == 1:
            l2[1]-=1
            if not l2[1] in d1:
                d1[l2[1]] = prev
            sum1-=d1[l2[1]]
            d1[l2[1]] = l2[2]
            sum1 += d1[l2[1]]
        else:
            prev = l2[1]
            sum1 = n*l2[1]
            d1.clear()
    
        print(sum1)


