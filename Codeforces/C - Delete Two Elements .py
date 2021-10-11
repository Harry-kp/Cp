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
    d1 = {}
    for i in range(n):
        if l1[i] in d1:
            d1[l1[i]]+=1
        else:
            d1[l1[i]] = 1
    
    sum1 = sum(l1)

    ab = (2*sum1)//n

    if ab*n != 2*sum1:
        print('0')
    else:
        ans = 0
        for i in l1:
            if ab-i in d1:
                ans += d1[ab-i]
            
            if ab-i == i:
                ans-=1
        print(ans//2)



