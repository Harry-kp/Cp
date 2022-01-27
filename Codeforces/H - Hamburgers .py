from sys import stdin
from tkinter.tix import InputOnly
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

def good(ham):
    if(ham * hb<=nb and ham*hs<=ns and ham*hc<=nc):
        return True
    wb = max(0,(ham*hb - nb))
    ws = max(0,(ham*hs - ns))
    wc = max(0,(ham*hc - nc))
    return wb*pb + ws*ps + wc*pc<=r
    

def solve():
    l=0
    r=1e18+10

    while l+1<r:
        m=(l+r)//2
        if good(m):
            l=m
        else:
            r=m
    return int(l)

t = 1
# t = ii()
for _ in range(t):
    rec = input()
    hb=hs=hc=0
    for i in rec:
        if i=='B':
            hb+=1
        elif i=='S':
            hs+=1
        else:
            hc+=1
    
    nb,ns,nc=mi()
    pb,ps,pc=mi()
    r=ii()
    print(solve())


