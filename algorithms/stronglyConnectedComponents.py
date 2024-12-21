from sys import setrecursionlimit

n, m = map(int, input().split())
setrecursionlimit(m)

# Это dfs для топологической сортировки
def dfs1(v):
    visited[v] = 1
    for to in reversed_g[v]:
        if not visited[to]:
            dfs1(to)

    top_sort_order.append(v)

# Это dfs для раскраски вершин
def dfs2(v, component):
    visited[v] = component
    for to in g[v]:
        if not visited[to]:
            dfs2(to, component)
            

g = [[] for _ in range(n)]
reversed_g = [[] for _ in range(n)]
for _ in range(m):
    f, t = map(int, input().split())
    f -= 1
    t -= 1

    g[f].append(t)
    reversed_g[t].append(f)

# Сперва ищем вершины, от которых будем запускать dfs для выделения компонент сильной связности
visited = [0 for _ in range(n)]
top_sort_order = []
for v in range(n):
    if not visited[v]:
        dfs1(v)

top_sort_order.reverse()

# Затем красим вершины
visited = [0 for _ in range(n)]
component_number = 0
for v in top_sort_order:
    if not visited[v]:
        component_number += 1
        dfs2(v, component_number)

for v in visited:
    print(v, end=' ')
