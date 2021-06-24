from io import BytesIO, IOBase
import math
import time
import sys
import os
from math import gcd, floor, sqrt, log
start_time = time.time()
def iin(): return int(input())
def sin(): return input().strip()
def listin(): return list(map(int, input().strip().split()))
def liststr(): return list(map(str, input().strip().split()))
def ceill(x): return int(x) if(x == int(x)) else int(x)+1
def ceilldiv(x, d): return x//d if(x % d == 0) else x//d+1
def LCM(a, b): return (a*b)//gcd(a, b)


n, m = listin()
s = sin()
z = ""
j = 1
for i in range(1, n):
    if s[i] < s[i % j]:
        j = i + 1
    elif s[i] != s[i % j]:
        break

for i in range(0, m):
    z += s[i % j]
print(z)
