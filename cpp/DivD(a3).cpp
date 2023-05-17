#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<vector<int>> g(1e5 + 1);
vector<int> depths(1e5+1);
vector<int> parrent(1e5+1);

void dfs(int v, int p) {
    parrent[v] = p;

    if (p != -1)
        depths[v] = depths[p] + 1;
    
    for (auto to : g[v])
        if (to != p) 
            dfs(to, v);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; 
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int to;
        cin >> to;
        g[i].push_back(to-1);
        g[to-1].push_back(i);
    }

    if (n == 2) {
        cout << "1 2";
        return 0;
    }

    depths[0] = 0;
    dfs(0, -1);
    int u = 0;
    for (int i = 0; i < n; i++)
        if (depths[i] > depths[u])
            u = i;
    
    depths[u] = 0;
    dfs(u, -1);
    int v = 0;
    for (int i = 0; i < n; i++)
        if (depths[i] > depths[v])
            v = i;

    int d = depths[v];
    int p1 = d / 2;
    int p2 = (d + 1) / 2;

    int cur = v;
    vector<int> answer;
    while (depths[cur] != 0) {
        if (depths[cur] == p1 || depths[cur] == p2)
            answer.push_back(cur);
        
        cur = parrent[cur];
    }

    for (auto el : answer)
        cout << el + 1 << ' ';

    return 0;
}