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
# t = ii()
for _ in range(t):
    N = ii()
    ans  = []
    while N:  #32
        n = N  #32
        summands = 0
        p = 1
        while n:
            if n%10!=0: 
                summands+=p
            p*=10
            n//=10
        N-=summands
        ans.append(summands)
    
    print(len(ans))
    print(*ans)


