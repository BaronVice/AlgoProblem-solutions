n = int(input())
a = int(input())
b = int(input())

pairs = []
for _ in range(n):
    pairs.append([0, 0])

if n == 1:
    print(1) if a == b else print(0)
    print(a, b, sep = ':')
    exit(0)

if a + b <= n:
    print(n-a-b)
    for i in range(a):
        pairs[i][0] = 1
    for i in range(a, a+b):
        pairs[i][1] = 1
    

else:
    print(0)
    if a >= n-1:
        for i in range(n-2):
            pairs[i][0] = 1
            a -= 1

        if b == 0:
            pairs[-2][0] = a-1
            pairs[-1][0] = 1
        else:
            pairs[-2][0] = a
            pairs[-1][1] = b

    else:
        for i in range(a):
            pairs[i][0] = 1

        for i in range(a, n-1):
            pairs[i][1] = 1
            b -= 1
        pairs[n-1][1] = b
        
        
for pair in pairs:
    print(*pair, sep=':')