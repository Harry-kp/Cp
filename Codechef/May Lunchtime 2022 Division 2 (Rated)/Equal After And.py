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
    n, m = mi()
    l1 = li()

    l1.sort()
    ans = 0
    j = n-1
    i = n-1
    ans = l1[-1]*2
    while i <= j and i >= 0:
        mx = max((l1[i]-l1[j]) % m, (l1[j]-l1[i]) % m)
        if ans <= l1[i] + l1[j] + mx:
            ans = l1[i] + l1[j] + mx
            i -= 1
        else:
            j -= 1

    print(ans)

