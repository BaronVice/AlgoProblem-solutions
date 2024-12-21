from sys import maxsize as INT_MAX
from collections import deque

n, m = ...

class node:
    def __init__(self, to, weight):
        self.to = to
        self.weight = weight

edges = [0] * n
for i in range(n):
    edges[i] = []


def zeroOneBFS(src: int):
    dist = [0] * n
    for i in range(n):
        dist[i] = INT_MAX

    q = deque()
    dist[src] = 0
    q.append(src)

    while q:
        v = q[0]
        q.popleft()

        for i in range(len(edges[v])):

            if (dist[edges[v][i].to] > 
                dist[v] + edges[v][i].weight):
                dist[edges[v][i].to] = dist[v] + edges[v][i].weight

                if edges[v][i].weight == 0:
                    q.appendleft(edges[v][i].to)
                else:
                    q.append(edges[v][i].to)

    for i in range(n):
        print(dist[i], end = " ")
    print()

def addEdge(u: int, v: int, wt: int):
    edges[u].append(node(v, wt))
    edges[u].append(node(v, wt))


if __name__ == "__main__":
    # m = 13
    addEdge(0, 1, 0)
    addEdge(0, 7, 1)
    addEdge(1, 7, 1)
    addEdge(1, 2, 1)
    addEdge(2, 3, 0)
    addEdge(2, 5, 0)
    addEdge(2, 8, 1)
    addEdge(3, 4, 1)
    addEdge(3, 5, 1)
    addEdge(4, 5, 1)
    addEdge(5, 6, 1)
    addEdge(6, 7, 1)
    addEdge(7, 8, 1)

    src = 0
    zeroOneBFS(src)
    
