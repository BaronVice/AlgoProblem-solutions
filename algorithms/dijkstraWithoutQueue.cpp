#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, s;
vector<vector<pii>> g;
vector<bool> visited;
vector<int> dist;

void bfs(){
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++){
            if (!visited[j] && (v == -1 || dist[v] > dist[j]))
                v = j;
        }

        if (v == -1 || dist[v] == 1e9)
            break;
        
        visited[v] = true;
        for (auto & p : g[v]){
            int to = p.second;
            int weight = p.first;

            if (dist[v] + weight < dist[to]){
                dist[to] = dist[v] + weight;
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
    
    bfs();

    return 0;
}