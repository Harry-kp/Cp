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
        n,k1,k2 = mi()
        w,b = mi()
     
        if(w == 0 and b == 0):
            print("YES")
        elif w>0 and b == 0:
            if(2*w <= k1+ k2):
                print("YES")
            else:
                print("NO")
        elif w == 0 and b>0:
            if 2*n - k1 - k2 >= 2*b:
                print("YES")
            else:
                print("NO")
        elif w>0 and b>0:
            if(2*w <= k1+ k2 and 2*n - k1 - k2 >= 2*b):
                print("YES")
            else:
                print("NO")