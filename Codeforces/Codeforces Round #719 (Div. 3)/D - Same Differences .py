from sys import stdin, stdout
import math
from collections import deque, Counter, OrderedDict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
import heapq
# from functools import reduce


def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()

# ans = []
# for i in range(1,10):
#     ans.append(9*i)


t = ii()
for _ in range(t):
    n = ii()
    l1 = li()
    for i in range(n):
        l1[i] -= i
    ans = 0
    dict1 = {}
    for i in l1:
        if i in dict1:
            dict1[i] += 1
        else:
            dict1[i] = 1

    for i in dict1.keys():
        if dict1[i] >= 2:
            ans += (dict1[i]*(dict1[i]-1))//2
    print(ans)
