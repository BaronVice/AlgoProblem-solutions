# Количество вершин, ребер
n, m = [int(item) for item in input().split()]
# Сам граф
graph = [[] for _ in range(n+1)] 
# Количество входящих в вершину ребер
in_vertex = [0]*(n+1)
for _ in range(m):
    v1, v2 = [int(item) for item in input().split()]
    graph[v1].append(v2)
    in_vertex[v2] += 1

ans = []
queue = list()
for i in range(1, n+1):
    if not in_vertex[i]:
        queue.append(i)


while len(queue):
    v = queue[0]
    for i in graph[v]:
        in_vertex[i] -= 1
        if in_vertex[i] == 0:
            queue.append(i)
    ans.append(v)
    del queue[0]

# Если количество вершин после сортировки не равно количеству вершин графа, то посортировать не получилось
if len(graph)-1 == len(ans):
    print(*ans)
else:
    print(-1) 
