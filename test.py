MOD = 1000000007

n, q = map(int, input().split())
ranges = []
for i in range(q):
    t, l, r = map(int, input().split())
    ranges.append((t, l, r))

l1, r1 = 1, n
for t, l, r in ranges:
    if t == 1:
        l1 = max(l1, l)
        r1 = min(r1, r)

cases = 1 << (r1 - l1 + 1)

for t1, l1, r1 in ranges:
    for t2, l2, r2 in ranges:
        if l1 == l2 and r1 == r2 and t1 == 1 and t2 == 2:
            print(0)
            exit()

for t, l, r in ranges:
    if t == 2:
        cases = cases * (pow(2, l - 1, 1000000007)) % 1000000007
        cases = cases * (pow(2, n - r - 1, 1000000007)) % 1000000007

print(cases)
