for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    while len(a) > 0 and a[-1] == 0:
        a.pop()
    a.reverse()
    while len(a) > 0 and a[-1] == 0:
        a.pop()
    print(a.count(0))
