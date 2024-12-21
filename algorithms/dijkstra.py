n, m, s = map(int, input().split())
g = [[] for _ in range(n)]
visited = [0 for _ in range(n)]
dist = [10**9 for _ in range(n)]

def bfs():
    for i in range(n):
        v = -1
        for j in range(n):
            if not visited[j] and (v == -1 or dist[v] > dist[j]):
                v = j

        if v == -1 or dist[v] == 1e9:
            break
        
        visited[v] = True
        for p in g[v]:
            to = p[1]
            weight = p[0]

            if dist[v] + weight < dist[to]:
                dist[to] = dist[v] + weight

for _ in range(m):
    f, t, weigth = map(int, input().split())
    f -= 1
    t -= 1
    g[f].append([weigth, t])
    g[t].append([weigth, f])

visited[s] = True
dist[s] = 0
    
bfs()
