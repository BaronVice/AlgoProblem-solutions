#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, s;
vector<vector<pii>> g;
vector<bool> visited;
vector<int> dist;
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

            if (dist[v] + weight < dist[to]){
                dist[to] = dist[v] + weight;
                q.push({dist[to], to});
            }
        }
    }
}

int main(){
    cin >> n;
    g.resize(n);
    visited.resize(n);
    dist.resize(n, 1e9);

    cin >> s;
    visited[s] = true;
    dist[s] = 0;
    q.push({dist[s], s});

    bfs();

    return 0;
}