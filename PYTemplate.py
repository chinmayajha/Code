# import time
# from ast import Try
# from io import BytesIO, IOBase
# import os
# import sys
# import math
# from math import gcd, floor, sqrt, log
# BUFSIZE = 8192


# class FastIO(IOBase):
#     newlines = 0

#     def __init__(self, file):
#         self._fd = file.fileno()
#         self.buffer = BytesIO()
#         self.writable = "x" in file.mode or "r" not in file.mode
#         self.write = self.buffer.write if self.writable else None

#     def read(self):
#         while True:
#             b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
#             if not b:
#                 break
#             ptr = self.buffer.tell()
#             self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
#         self.newlines = 0
#         return self.buffer.read()

#     def readline(self):
#         while self.newlines == 0:
#             b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
#             self.newlines = b.count(b"\n") + (not b)
#             ptr = self.buffer.tell()
#             self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
#         self.newlines -= 1
#         return self.buffer.readline()

#     def flush(self):
#         if self.writable:
#             os.write(self._fd, self.buffer.getvalue())
#             self.buffer.truncate(0), self.buffer.seek(0)


# class IOWrapper(IOBase):
#     def __init__(self, file):
#         self.buffer = FastIO(file)
#         self.flush = self.buffer.flush
#         self.writable = self.buffer.writable
#         self.write = lambda s: self.buffer.write(s.encode("ascii"))
#         self.read = lambda: self.buffer.read().decode("ascii")
#         self.readline = lambda: self.buffer.readline().decode("ascii")


# sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
# def input(): return sys.stdin.readline().rstrip("\r\n")


# input: lambda: sys.stdin.readline().rstrip()
# start_time = time.time()
# def iin(): return int(input())
# def sin(): return input()
# def listin(): return list(map(int, input().split()))
# def liststr(): return list(map(str, input().split()))
# def ceill(x): return int(x) if(x == int(x)) else int(x)+1
# def ceilldiv(x, d): return x//d if(x % d == 0) else x//d+1
# def LCM(a, b): return (a*b)//gcd(a, b)


q = int(input())
s = "1"
for i in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        s += str(query[1])
    elif query[0] == 2:
        s = s[1:]
    else:
        t = s
        if len(t) > 15:
            t = int(t[len(t) - 14:])
        t = int(t)
        print(t % 998244353)
        print(int(s) % 998244353, t % 998244353)
