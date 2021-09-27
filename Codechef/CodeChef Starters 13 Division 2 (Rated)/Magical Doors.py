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
    s = input()

    flip = False
    ans = 0
    for i in range(len(s)):
        if flip and s[i] == '1':
            ans +=1
            flip = not flip
        elif not flip and s[i] == '0':
            ans += 1
            flip = not flip
    print(ans)


