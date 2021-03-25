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
    n,m,x = mi()
    
    a = x%n
    if a == 0:
        a = n-1
    else:
        a = a - 1
    b = math.ceil(x/n)
    
    print(m*(a) + b)