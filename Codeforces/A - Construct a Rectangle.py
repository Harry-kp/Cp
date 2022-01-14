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


def solve(a,b,c):
    
    if a-b>=1 and a-b == c:
        return True
    
    if a-c>=1 and a-c == b:
        return True
    
    if b == c and a%2 == 0:
        return True
    return False

t = 1
t = ii()
for _ in range(t):
    a,b,c = mi()

    if solve(a,b,c) or solve(b,a,c) or solve(c,a,b):
        print("YES")
    else:
        print("NO")
