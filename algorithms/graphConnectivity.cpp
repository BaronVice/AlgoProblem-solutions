#include <bits/stdc++.h>

using namespace std;

// Списки смежности
vector<vector<int>> g;
// Посещенные
vector<bool> visited;
// Количество вершин и ребер
int n, m;

void dfs(int point){
    // Заходим в вершину и отмечаем ее посещенной
    visited[point] = true;
    // Для каждой вершины, в которую мы можем прийти из текущей: заходим в нее, если она не посещена
    for (auto el : g[point]) if (! visited[el]) {
        dfs(el);
    }
}

int main(){
    cin >> n >> m;
    // В задачах обычно счет вершин начинается с 1 (но в массивах счет с 0). Поэтому сделаем resize не на n, а на n+1
    g.resize(n+1);
    visited.resize(n+1);

    while(m--){
        // Между какими вершинами есть ребро
        int from, to; cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    } 

    // Начнем обход с первой вершины
    dfs(1);

    // Граф связный, если от любой вершины можно посетить любую другую
    // Поэтому, если все вершины посещены - граф связный, иначе нет
    bool result = true;
    for(int i = 1; i < n+1; i++){
        if (!visited[i]) result = false;
    }
    cout << (result ? "YES\n" : "NO\n");

    return 0;
}
