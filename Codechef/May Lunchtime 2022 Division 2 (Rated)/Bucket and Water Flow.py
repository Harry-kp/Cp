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
    w,x,y,z = mi()

    tot = y*z

    if w+tot>x:
        print('overflow')
    elif w+tot == x:
        print('filled')
    else:
        print('unfilled')

