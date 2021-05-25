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


t = 1
t = ii()
for _ in range(t):
    n = ii()
    s = input()
    zero = s.count('0')
    one = n-zero

    if(one == n):
        print('DRAW')
    elif zero == 1:
        print('BOB')
    else:
        if(n % 2 == 0):
            print('BOB')
        else:
            if(s[n//2] == '0'):
                print('ALICE')
            else:
                print('BOB')
