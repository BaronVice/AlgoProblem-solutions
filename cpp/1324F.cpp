#include <bits/stdc++.h>


/*  Сделаем два dfs'а - первым посчитаем максимумы разниц белые-черные для каждой вершины,
вторым распределим ответы от корня до остальных вершин */
using namespace std;

int n;
vector<int> colors;
vector<vector<int>> tree;

void dfs(int point, int parrent){
    for (auto child : tree[point])
        if (child != parrent){
            dfs(child, point);
            // Если child положительный - берем его
            colors[point] += (colors[child] > 0 ? colors[child] : 0);
        }
}

void dfs_answer(int point, int parrent){
    for (auto child : tree[point])
        if (child != parrent){
            // Если child > 0, то он состоит в сумме ответа текущей вершины
            if (colors[child] >= 0)
                /* Текущая вершина может иметь сумму большую/равную child'а,
                если у текущей вершины есть и другие положительные поддеревья помимо child'a.
                Или текущая врешина черная и единственное поддерево - child,
                что значит сумма текущей вершины на 1 меньше суммы child */
                colors[child] = max(colors[child], colors[point]);
            // Если child отрицательный, то для его максимума подцепим к текущей вершине
            // (только если текущая вершина не содержит результата -1, иначе при подцеплении будет -2)
            else
                colors[child] = max(colors[child], colors[point]-1);

            dfs_answer(child, point);
        }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    colors.resize(n+1);
    tree.resize(n+1);

    for (int i = 1; i <= n; i++){
        bool c; cin >> c;
        colors[i] = (c ? 1 : -1);
    }

    for (int i = 1; i < n; i++){
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    dfs(1, -1);
    dfs_answer(1, -1);

    for (int i = 1; i <= n; i++){
        cout << colors[i] << ' ';
    }

    return 0;
}