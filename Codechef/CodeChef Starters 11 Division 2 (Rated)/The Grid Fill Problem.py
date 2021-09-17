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

    ans = [[1 for i in range(n)] for j in range(n)]

    if n%2 == 0:
        for i in range(n):
            for j in range(n):
                print(-1,end = " ")
            print('')
    else:
        i = 0
        while i<n:
            ans[i][i] = -1
            i+=1
        for i in ans:
            print(*i)
