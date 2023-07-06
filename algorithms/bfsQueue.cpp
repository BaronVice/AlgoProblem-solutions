#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

int n, s;
vector<vector<int>> g;
vector<int> visited;
vector<int> dist;
queue<int> q;

void bfs(){
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (auto el : g[v]){
            if (!visited[el]){
                visited[el] = true;
                dist[el] = dist[v] + 1;
                q.push(el);
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
    q.push(s);

    bfs();

    return 0;
}