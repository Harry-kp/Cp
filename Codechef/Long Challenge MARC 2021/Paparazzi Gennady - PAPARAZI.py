from sys import stdin,stdout
import math
# from collections import deque,Counter,OrderedDict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# import heapq
# from functools import reduce
import math
def ii():return int(stdin.readline())
def mi():return map(int,stdin.readline().split())
def li():return list(mi())
def si():return stdin.readline()

def slope(p1,p2):
    return (p2[1] - p1[1])/(p2[0] - p1[0])


for _ in range(ii()):
    n = ii()
    l1 = [(i+1,v) for i,v in enumerate(li())]

    ans = 1
    stack = []
    stack.append(l1[0])
    stack.append(l1[1])

    for i in range(2,n):
        while(len(stack)>=2):
            
            if slope(l1[i],stack[-1])>=slope(stack[-2],l1[i]):
                stack.pop()
            else:
                break
        stack.append(l1[i])
        ans = max(ans,abs(stack[-1][0] - stack[-2][0]))

    print(ans)