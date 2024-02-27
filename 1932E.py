for _ in range(int(input())):
    n = int(input())
    a = input().lstrip('0')
    n = len(a)

    temp = [0] * (n + 1)
    temp[1] = int(a[0])

    for i in range(1, n):
        temp[i + 1] = temp[i] + int(a[i])

    for i in range(n, 0, -1):
        temp[i - 1] += temp[i] // 10
        temp[i] = temp[i] % 10

    temp = temp[::-1]
    while temp[-1] == 0:
        temp.pop()
    temp = [str(i) for i in temp][::-1]

    print("".join(temp))
        
