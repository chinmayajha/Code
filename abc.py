def find_beauty_value(arr):
    n = len(arr)
    beauty_sum = 0
    for i in range(n):
        for j in range(i+1, n):
            subarray = arr[i:j+1]
            subarray.sort()
            if len(subarray) >= 2:
                beauty_sum += subarray[0] ^ subarray[1]
    return beauty_sum


t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    beauty_sum = find_beauty_value(arr)
    print(beauty_sum)
