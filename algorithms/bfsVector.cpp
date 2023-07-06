#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n, s, qb = 0, qe = 1;
vector<vector<int>> g;
vector<int> visited;
vector<int> dist;
vector<int> q;

void bfs(){
    while (qb != qe){
        int v = q[qb++];
        for (auto el : g[v]){
            if (!visited[el]){
                visited[el] = true;
                dist[el] = dist[v] + 1;
                q[qe++] = el;
            }
        }
    }
}

int main(){
    cin >> n;
    g.resize(n);
    visited.resize(n);
    dist.resize(n, 1e9);
    q.resize(n);

    cin >> s;
    visited[s] = true;
    dist[s] = 0;
    q[qb] = s;

    bfs();

    return 0;
}