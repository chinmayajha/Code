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


def isprime(n):
    for i in range(2, math.sqrt(n)+1):
        if n % i == 0:
            return False
    return True


def solve():
    n = iin()


# t = int(input())
for hula in range(t):
    solve()
# sys.stderr.write(str(time.time()-start_time))
