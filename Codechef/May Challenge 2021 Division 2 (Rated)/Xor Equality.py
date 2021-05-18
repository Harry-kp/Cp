from sys import stdin, stdout
import math
# from collections import deque,Counter,OrderedDict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# import heapq
# from functools import reduce


def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()

mod = 10**9+7
ans = [0]*100005
ans[1] = 1
for i in range(2,100005):
    ans[i] = (2*ans[i-1])%mod

for _ in range(ii()):
    print(ans[ii()])
