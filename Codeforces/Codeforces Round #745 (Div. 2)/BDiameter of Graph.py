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
import math
t = 1
t = ii()
for _ in range(t):
    n,m,k = mi()

    if n == 1 and m == 0 and 0<k-1:
        print("YES")
        continue
    max_edge = n*(n-1)//2
    min_edge = n-1

    if m<min_edge or m>max_edge:
        print('NO')
    else:
        if m == max_edge:
            if 1<k-1:
                print('YES')
            else:
                print("NO")
        else:
            if 2<k-1:
                print('YES')
            else:
                print("NO")

        
        
 
