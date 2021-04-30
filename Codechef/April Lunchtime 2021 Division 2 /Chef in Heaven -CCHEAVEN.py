from sys import stdin, stdout
import math
from collections import deque, Counter, OrderedDict, defaultdict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# import heapq
# from functools import reduce


def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()


for _ in range(ii()):
    n = ii()
    s = input()

    zero = 0
    one = 0

    for i in s:
        if i == '1':
            one += 1
        else:
            zero += 1
        if one >= zero:
            print('YES')
            break
    else:
        print('NO')
