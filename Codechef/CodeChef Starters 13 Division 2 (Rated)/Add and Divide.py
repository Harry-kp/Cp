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


def pow(x, y):

    res = 1

    while (y > 0):
        if ((y & 1) != 0):
            res = res * x
        y = y >> 1  
        x = x * x  
    return res

def solve(a, b):
    for i in range(1,51):
        if pow(b,i)%a == 0:
            return True
    return False

t = 1
t = ii()

for _ in range(t):
    a,b = mi()
    
    if solve(a,b):
        print('YES')
    else:
        print('NO')





