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

def solve(A,n):
    B = list(sorted(A))

    cost = 0
    for i in range(n-1):
        b = A.index(B[i])
        cost += abs(b-i + 1)

        A[i:b+1] = A[i:b+1][::-1]
    
    return cost

t = ii()
for _ in range(t):
    n = ii()
    l1 = li()
    print(f"Case #{_+1}: {solve(l1,n)}")



        
