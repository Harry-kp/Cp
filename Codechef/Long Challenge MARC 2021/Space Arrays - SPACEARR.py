from sys import stdin,stdout
import math
# from collections import deque,Counter,OrderedDict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# import heapq
# from functools import reduce
def ii():return int(stdin.readline())
def mi():return map(int,stdin.readline().split())
def li():return list(mi())
def si():return stdin.readline()



for _ in range(ii()):
    n = ii()
    l1 = li()
    l1.sort()

    sum1 = 0
    for i in range(n):
        if l1[i]>i+1:
            print("Second")
            break
        sum1 += (i+1 - l1[i])
    else:
        if abs(sum1&1 == 1):print("First")
        else:print("Second")
        

