from sys import stdin,stdout
import math
# from collections import deque,Counter,OrderedDict
# from itertools import permutations,combinations,combinations_with_replacement
# from operator import itemgetter
# import heapq
# from functools import reduce
 
def ii():return int(stdin.readline())
def mi():return map(int,stdin.readline().split())
def li():return list(mi())
def si():return stdin.readline()
 
for _ in range(ii()):
 
    s1 = si().strip('\n')
    s2 = si().strip('\n')
 
    n1 = len(s1)
    n2  =  len(s2)
 
    l1 = []
    l2 = []
    # l1.append(' ')
    # l2.append(' ')
 
    for i in range(n1):
        # s = ''
        for j in range(i,n1):
            l1.append(s1[i:j+1])
    for i in range(n2):
        # s = ''
        for j in range(i,n2):
            l2.append(s2[i:j+1])
    
    max1 = 0
    # print(l1)
    # print(l2)
    for i in l1:
        for j in l2:
            if i == j:
                max1 = max(max1,len(i))
    
 
    print(n1 + n2 - 2*max1)