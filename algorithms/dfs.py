def dfs(graph, visited, now):
    visited[now] = True
    paths.append(now)
    for neig in graph[now]:
        if not visited[neig]:
            dfs(graph, visited, neig)
            paths.append(now)
            
# Ввод данных и инициализация графа
n, m, start = [int(item) for item in input().split()]
graph = [[] for _ in range(n+1)] 
visited = [0] * (n+1)
paths = []   # здесь записываем путь обхода

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
            
# Обход графа с вершины v
dfs(graph, visited, start) 

print(len(paths))
print(*paths)
