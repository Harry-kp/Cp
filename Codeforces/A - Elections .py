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
    a,b,c = mi()
    print(max(0,max(b,c)+1-a),end=' ')
    print(max(0, max(a, c)+1-b), end=' ')
    print(max(0, max(a, b)+1-c))

    

