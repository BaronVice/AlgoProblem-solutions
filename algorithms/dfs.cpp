#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;

vb visited;
vvi graph;

void dfs(int v){
    visited[v] = true;
    for(auto el : graph[v]){
        if (! visited[el]){
            dfs(el);
        }
    }
}

int main(){
    int n; cin >> n;
    visited.resize(n+1);
    graph.resize(n+1);

    // ...graph input...
}
