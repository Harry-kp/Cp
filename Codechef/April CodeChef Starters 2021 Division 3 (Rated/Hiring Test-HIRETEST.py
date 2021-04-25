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


for _ in range(ii()):
    n, m = mi()
    x, y = mi()
    for i in range(n):
        s = input()
        c = 0
        p = 0
        for j in s:
            if j == 'F':
                c += 1
            elif j == 'P':
                p += 1

        if c >= x or (c == x-1 and p >= y):
            print('1', end="")
        else:
            print('0', end='')
    print('')
