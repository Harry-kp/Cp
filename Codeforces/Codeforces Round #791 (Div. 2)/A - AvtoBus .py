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
t = ii()
for _ in range(t):
    n = ii()

    # 4x+6y = c
    # if gcd(4,6) i.e 2 does not divides c completly, then no solution
    # or directly if n<4 print -1
    
    if n<4 or n&1:
        print(-1)
        continue

    # maximum when all are 4 tyre bus
    # minimum when all are 6 tyre bus
    # +5 to include case when n%6 is greater or equal to 4 but not 0,hence one more bus will be added
    print((n+5)//6,n//4)
