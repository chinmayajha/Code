import math,time,sys,os
from math import gcd,floor,sqrt,log
start_time = time.time()
def iin(): return int(input())
def sin(): return input().strip()
def listin(): return list(map(int,input().strip().split()))
def liststr(): return list(map(str,input().strip().split()))
def ceill(x): return  int(x) if(x==int(x)) else int(x)+1
def ceilldiv(x,d): x//d if(x%d==0) else x//d+1
def LCM(a,b): return (a*b)//gcd(a,b)

def solve():
    s = sin().split("vv")
    print(s)
    s.pop(0)
    s.pop(-1)
    ###############
    ans = 0
    a = []
    for i in range(len(s)):
        s[i] = s[i].count('o')
    print(s)
        


t = 1 
# t = int(input()) 
for hula in range(t):
	solve()
sys.stderr.write(str(time.time()-start_time))


