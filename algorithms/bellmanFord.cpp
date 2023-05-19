#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
int v, e, s;
// each subarray is u, v, w
vector<vector<int>> g;
vector<int> dist;
const int INF = 1e9;

void bellmanFord(){
    for (int i = 0; i < v - 1; i++) {
        for (int j = 0; j < e; j++) {
            if (dist[g[j][0]] != INF)
                dist[g[j][1]] = min(dist[g[j][1]], dist[g[j][0]] + g[j][2]);
        }
    }
    
    // Here is a check for negative cycle
    for (int i = 0; i < e; i++) {
        int x = g[i][0];
        int y = g[i][1];
        int weight = g[i][2];
        if (dist[x] != INF && dist[x] + weight < dist[y])
            // Contains negative cycle
            cout << 1 << endl;
            break;
    }
 
    for (int i = 0; i < v; i++)
        cout << i << " " << dist[i] << endl;
}
 

int main()
{
    dist.resize(v, INF);
    cin >> s;
    dist[s] = 0;
 
    bellmanFord();
    return 0;
}