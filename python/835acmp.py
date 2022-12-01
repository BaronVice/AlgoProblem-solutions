

n, w = map(int, input().split())

cost = [0] * (n+1)
weights = [0] * (n+1)

memo = [[0] * (w+1)] * (n+1)
for i in range(1, n+1):
    weights[i], cost[i] = map(int, input().split())

for i in range(1, n+1):
    for j in range(1, w+1):
        if weights[i] <= j:
            memo[i][j] = max(memo[i-1][j], cost[i] + memo[i-1][j-weights[i]])
        else:
            memo[i][j] = memo[i-1][j]

print(memo[n][w])
