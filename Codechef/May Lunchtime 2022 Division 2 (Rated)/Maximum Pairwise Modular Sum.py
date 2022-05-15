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

    #ans = 1 and then calculate ans&=i for i...n cost me 30 points
    
    ans = l1[0]
    for i in l1[1:]:
        ans &= i
    if(l1.count(ans) == n):
        print(0)
        continue

    c1 = 0
    curr = l1[0]

    for i in l1[1:]:
        if curr != ans:
            curr &= i
            c1 += 1
        else:
            curr = i

    if(curr != ans):
        c1 += 1
    c2 = 0
    l1 = l1[::-1]
    curr = l1[0]
    for i in l1[1:]:

        if curr != ans:
            curr &= i
            c2 += 1
        else:
            curr = i
    if(curr != ans):
        c2 += 1
    print(min(c1, c2))

