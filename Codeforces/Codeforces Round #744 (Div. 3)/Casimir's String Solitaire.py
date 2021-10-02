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
    s = si()
    a = s.count('A')
    b = s.count('B')
    c = s.count('C')
    # print(a,b,c)
    if c == 0:
        if a == b:
            print('YES')
        else:
            print('NO')
    elif a == 0:
        if b == c:
            print('YES')
        else:
            print('NO')
    else:
        if a+c == b:
            print('YES')
        else:
            print('NO')
