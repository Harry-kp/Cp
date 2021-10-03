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
    n, x = mi()
    l1 = li()
    l2 = []
    for ind, val in enumerate(l1):
        l2.append([val, ind])

    l2.sort()

    for i in range(n):
        ind = l2[i][1]

        if l2[i][0] == l1[i]:
            continue

        if not(abs(n-i-1) >= x or abs(i) >= x):
            # print(i,ind)
            print("NO")
            break
    else:
        print("YES")


