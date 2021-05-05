from sys import stdin, stdout
import math
# from collections import deque,Counter,OrderedDict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
import heapq
# from functools import reduce


def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()


t = 1
t = ii()
for _ in range(t):
    dict1 = {}
    n = ii()
    l1 = list(input())
    prev = l1[0]
    dict1[l1[0]] = 0
    if n == 1:
        print('YES')
        continue
    for i in range(1, n):
        if l1[i] == prev:
            continue
        if l1[i] in dict1:
            print('NO')
            break
        if l1[i] not in dict1:
            dict1[l1[i]] = 0
        prev = l1[i]
    else:
        print('YES')
