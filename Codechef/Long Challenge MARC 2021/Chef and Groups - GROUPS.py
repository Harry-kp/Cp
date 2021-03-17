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
    c = 0
    s = si()
    prev = s[0]
    if(prev == '1'):c = 1
    else:c = 0
    
    for i in range(1,len(s)):
        if(prev == '0'):
            if(s[i] == '1'):
                c+=1
        prev = s[i]


                
        
    print(c)


