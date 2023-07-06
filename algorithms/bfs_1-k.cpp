#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

struct Node{
    int to, weight;
};

int n, s;
vector<vector<Node>> g;
vector<int> dist;
vector<queue<int>> q;

void bfs(){
    for (int d = 0; d < q.size(); d++){
        while (!q[d].empty()){
            int v = q[d].front();
            q[d].pop();

            for (auto el : g[v]){
                if (dist[el.to] > dist[v] + el.weight){
                    dist[el.to] = dist[v] + el.weight;
                    q[dist[el.to]].push(el.to);
                }
            }
        }
    }
}

int main(){
    cin >> n;
    g.resize(n);
    dist.resize(n, 1e9);

    cin >> s;
    dist[s] = 0;
    q[0].push(s);

    bfs();

    return 0;
}