from sys import stdin,stdout
import math
from itertools import permutations
# from collections import deque,Counter,OrderedDict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# import heapq
# from functools import reduce
def ii():return int(stdin.readline())
def mi():return map(int,stdin.readline().split())
def li():return list(mi())
def si():return stdin.readline()

# partial marks solved brute force n!
def solve(A,n):
    B = list(sorted(A))
    D = A.copy()

    cost = 0
    for i in range(n-1):
        b = D.index(B[i])
        cost += abs(b-i + 1)

        D[i:b+1] = D[i:b+1][::-1]
    
    return cost



tt = ii()
for t in range(tt):
    n,c = mi()
    if c<n-1 or c>(n*(n+1))//2 - 1:
        print(f"CASE #{t+1}: IMPOSSIBLE")

    A = [x for x in range(1,n+1)]

    permut = permutations(A)
    for per in permut:
        l1 = list(per)
        tmp = solve(list(per),n)
        if  tmp == c:
            print(f"CASE #{t+1}: ",end = '')
            for x in per:
                print(x,end = ' ')
            print()
            break
