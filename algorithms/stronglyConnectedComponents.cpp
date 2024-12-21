#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;

struct G {
    vector<vector<int>> g, reversed_g;
    vector<int> visited, top_sort_order;

    void input(){
        int n, m; cin >> n >> m;
        g.resize(n); reversed_g.resize(n);
        for (int i = 0; i < m; i++){
            int from, to; cin >> from >> to;
            from--; to--;
            g[from].push_back(to);
            reversed_g[to].push_back(from);
        }        
    }

    // Это dfs для топологической сортировки
    void dfs1(int v){
        visited[v] = 1;
        for (auto to : reversed_g[v]) if (!visited[to]) dfs1(to);

        top_sort_order.push_back(v);
    }
    
    // Это dfs для раскраски вершин
    void dfs2(int v, int component){
        visited[v] = component;
        for (auto to : g[v]) if (!visited[to]) dfs2(to, component);
    }

    vector<int> findSCC() {
        // Сперва ищем вершины, от которых будем запускать dfs для выделения компонент сильной связности
        visited.assign(g.size(), 0);
        for (int v = 0; v < g.size(); v++) if (!visited[v]) dfs1(v);

        reverse(top_sort_order.begin(), top_sort_order.end());

        // Затем красим вершины
        visited.assign(g.size(), 0);
        int component_number = 0;
        for(auto v: top_sort_order) if (!visited[v]){
            component_number++;
            dfs2(v, component_number);
        }
        
        // Для каждой вершины будет определен номер компоненты сильной связности, которой она принадлежит
        return visited;
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    G g = G();
    g.input();
    for(auto el : g.findSCC()){
        cout << el << ' ';
    }
}
