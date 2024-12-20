from collections import deque

def bfs(adj, s):
    # Очередь для обхода
    q = deque()
    # Путь обхода
    path = []
    
    # Изначально все вершины не посещены
    visited = [False] * len(adj)

    # Начинаем обход с вершины s, помечаем ее как посещенную
    visited[s] = True
    q.append(s)

    # Пока в очереди есть вершины на рассмотрение:
    while q:
        # Берем вершину из очереди
        curr = q.popleft()
        path.append(curr)
        # И от нее идем в соседние
        for x in adj[curr]:
            if not visited[x]:
                visited[x] = True
                q.append(x)
    
    return path

def add_edge(adj, u, v):
    adj[u].append(v)
    adj[v].append(u)


if __name__ == "__main__":
    V = 5

    adj = [[] for _ in range(V)]

    add_edge(adj, 0, 1)
    add_edge(adj, 0, 2)
    add_edge(adj, 1, 3)
    add_edge(adj, 1, 4)
    add_edge(adj, 2, 4)

    print("проход bfs от 0 вершины: ")
    print(*bfs(adj, 0))
