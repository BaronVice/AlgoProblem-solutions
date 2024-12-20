import sys
sys.setrecursionlimit(200000)

def dfs(graph, visited, now, comp):
    visited[now] = comp
    for neig in graph[now]:
        if not visited[neig]:
            dfs(graph, visited, neig, comp)
            

n, m = [int(item) for item in input().split()]
graph = [[] for _ in range(n+1)] 

for _ in range(m):
    v1, v2 = [int(item) for item in input().split()]
    # Проверка на петлю
    if v1 != v2:
        a = graph[v1]
        if v2 not in a:
            graph[v1].append(v2)
        a = graph[v2]
        if v1 not in a:
            graph[v2].append(v1) 
            
# Обход графа и раскраска вершин
visited = [0] * (n+1)
comp = 1
for i in range(1, n+1):
    if not visited[i]:
        dfs(graph, visited, i, comp) 
        comp += 1
        
comp = comp-1  #len(set(visited)) - 1       
print(comp)

print(*visited[1:])
