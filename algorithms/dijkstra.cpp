#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// Количество вершин и стартовая
int n, s;
// Граф
vector<vector<pii>> g;
// Посещенные
vector<bool> visited;
// Кратчайшие расстояния от s до dist[i]
vector<int> dist;
// Как и в bfs, будем закидывать сюда вершины, но приоритет отдаем с меньшим расстоянием (first - вес, second - номер вершины)
priority_queue<pii> q;

void bfs(){
    while (!q.empty()){
        int v = q.top().second;
        q.pop();

        if (visited[v])
            continue;
        
        visited[v] = true;

        for (auto & p : g[v]){
            int to = p.second;
            int weight = p.first;

            // Если от текущей могу перейти в соседнюю и улучшить ее расстояние
            if (dist[v] + weight < dist[to]){
                // То улучшаю расстояние соседней вершины и закидываю ее на рассмотрение
                dist[to] = dist[v] + weight;
                q.push({dist[to], to});
            }
        }
    }
}

int main(){
    cin >> n;
    g.resize(n+1);
    visited.resize(n+1);
    dist.resize(n+1, 1e9 /* максимальное расстояние от s до любой другой (гарантируется в условии либо max(веса_ребер) * n) */);

    cin >> s;
    visited[s] = true;
    dist[s] = 0;
    q.push({dist[s], s});

    bfs();

    return 0;
}
