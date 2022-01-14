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
    p = li()
    s = si()

    if s.count('0') == 0 or s.count('1') == 0:
        print(*p)
        continue
    up = []
    down = []
    for i in range(n):
        if s[i] == '0':
            down.append([p[i],i])
        else:
            up.append([p[i],i])
    
    ans = [0]*n
    up.sort()
    down.sort()
    # print(up,down)
    for i in range(n):
        if i<len(down):
            ans[down[i][1]] = i+1
        else:
            ans[up[i-len(down)][1]] = i+1
    
    print(*ans)




