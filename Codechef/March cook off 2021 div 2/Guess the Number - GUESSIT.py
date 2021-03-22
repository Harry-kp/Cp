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


t = ii()

for _ in range(t):
    for i in range(1,2001):

        print(i*i,flush = True)

        c = ii()

        if c == 0:
            continue
        else:
            break
