import random
for i in range(10):
    n = 1
    while n % 2 == 1:
        n = random.randint(1, 25)
    a = [random.randint(0, 1) for i in range(n)]
    print(n)
    print(*a)
