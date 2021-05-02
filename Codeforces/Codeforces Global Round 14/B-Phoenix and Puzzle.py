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


def div2(n):
    if n % 2 != 0:
        return False

    n //= 2
    a = int(math.sqrt(n))
    if a*a == n:
        return True
    return False


def div4(n):
    if n % 4 != 0:
        return False
    n //= 4
    a = int(math.sqrt(n))
    if a*a == n:
        return True
    return False


for _ in range(ii()):
    n = ii()
    if n == 1:
        print('NO')
    else:
        if div2(n) or div4(n):
            print('YES')
        else:
            print('NO')
