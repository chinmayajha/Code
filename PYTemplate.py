from ast import Try
from io import BytesIO, IOBase
import math
import time
import sys
import os
from math import gcd, floor, sqrt, log
input: lambda: sys.stdin.readline().rstrip()
start_time = time.time()
def iin(): return int(input())
def sin(): return input().strip()
def listin(): return list(map(int, input().strip().split()))
def liststr(): return list(map(str, input().strip().split()))
def ceill(x): return int(x) if(x == int(x)) else int(x)+1
def ceilldiv(x, d): x//d if(x % d == 0) else x//d+1
def LCM(a, b): return (a*b)//gcd(a, b)


def solve():
    n = iin()
    x, y = dict(), dict()
    cnt = 0
    temp = dict()
    for _ in range(n):
        a, b = listin()
        try:
            x[a] += 1
            y[b] += 1
        except:
            x[a] = 1
            y[b] = 1
        try:
            cnt -= temp[(a, b)]
        except:
            pass
        try:
            temp[(a, b)] += 1
        except:
            temp[(a, b)] = 1
        #############
    for i, j in x.items():
        if(j % 2 == 0):
            cnt += (j//2) * (j-1)
        else:
            cnt += (j) * ((j - 1)//2)
    for i, j in y.items():
        if(j % 2 == 0):
            cnt += (j//2) * (j-1)
        else:
            cnt += (j) * ((j - 1)//2)
    print(cnt)


t = 1
# t = int(input())
for hula in range(t):
    solve()
# sys.stderr.write(str(time.time()-start_time))
