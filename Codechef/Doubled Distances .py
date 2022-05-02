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
    l1 = li()
    l1.sort()

    ans = True
    for i in range(1, n-1):
        ans = ans & (((l1[i]-l1[i-1]) == 2*(l1[i+1]-l1[i])) |
                     (2*(l1[i]-l1[i-1]) == (l1[i+1]-l1[i])))

    if ans:
        print("YES")
        continue

    ans = True
    l2 = l1[::-1]
    for i in range(1, n-1):
        ans = ans & (((l2[i]-l2[i-1]) == 2*(l2[i+1]-l2[i])) |
                     (2*(l2[i]-l2[i-1]) == (l2[i+1]-l2[i])))

    if ans:
        print("YES")
        continue

    print("NO")

