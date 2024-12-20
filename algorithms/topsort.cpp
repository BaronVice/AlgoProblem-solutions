#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(
    vector<vector<int>>& adj,
    int V
){
    vector<int> indegree(V);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;

            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {
        int from, to; cin >> from >> to;
        from--;to--;
        edges.push_back({from, to});
    }

    vector<vector<int>> adj(n);

    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }

    vector<int> result = topologicalSort(adj, n);
    if (result.size() != n) {
        cout << -1;
    }
    else {
        for (auto i : result) {
            cout << i+1 << " ";
        }
    }
    
    return 0;
}
