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
    size = 1

    while(size*2<=n):
        size*=2
    print((size-1) * ((size-1) + (size*2-n)))


