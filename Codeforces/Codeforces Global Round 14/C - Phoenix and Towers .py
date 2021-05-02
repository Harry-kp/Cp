from sys import stdin, stdout
import math
# from collections import deque,Counter,OrderedDict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
import heapq
# from functools import reduce


def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()


for _ in range(ii()):
    n, m, x = mi()
    l1 = li()
    ans = [0]*n

    heapp = [[0, x] for x in range(1, m+1)]
    heapq.heapify(heapp)

    for i in range(n):
        node = heapq.heappop(heapp)
        ans[i] = node[1]
        node[0] += l1[i]
        heapq.heappush(heapp, node)
    print('YES')
    print(*ans)
