

t = int(input())

trees = []
for i in range(500):
    trees.append([0] * 500)

for _ in range(t):
    n, m = map(int, input().split())
    counter = 0

    for i in range(n):
        s = input()
        for j in range(m):
            if (s[j] == '*'):
                trees[i][j] = 1
                counter += 1
            else:
                trees[i][j] = 0

    for required_size in range(1, min(n, m)+1):
        for i in range(required_size, n):
            for j in range(required_size, m - required_size):
                if trees[i][j] >= 1:
                    if trees[i][j-1] >= required_size and trees[i-1][j] >= required_size and trees[i][j+1] >= required_size:
                        counter += 1
                        trees[i][j] = required_size + 1

    print(counter)
