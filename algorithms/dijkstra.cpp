#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// Функция сравнения (компаратор) для элементов priority_queue
struct compare {
   bool operator()(const pii& l, const pii& r){
        // В очередь закидываем pii, pii.first - дистанция, pii.second - вершина, в которую идем
        // Чем меньше дистанция, тем первее в очереди будет пара
        return l.first > r.first;
    }  
};  

// Количество вершин и стартовая
int n, s;
// Граф
vector<vector<pii>> g;
// Посещенные
vector<bool> visited;
// Кратчайшие расстояния от s до dist[i]
vector<int> dist;
// Как и в bfs, будем закидывать сюда вершины, но приоритет отдаем с меньшим расстоянием (first - вес, second - номер вершины)
// compare - функция по которой определяется приоритет (здесь чем меньше значение - тем выше приоритет)
priority_queue<pii, vector<pii>, compare> q;

void bfs(){
    while (!q.empty()){
        int v = q.top().second;
        q.pop();

        // cout << v << '\n';

        if (visited[v])
            continue;
        
        visited[v] = true;

        for (auto & p : g[v]){
            int to = p.second;
            int weight = p.first;

            // Если от текущей могу перейти в соседнюю и улучшить ее расстояние
            if (dist[v] + weight < dist[to]){
                // То улучшаю расстояние соседней вершины и закидываю ее на рассмотрение
                dist[to] = dist[v] + weight;
                q.push({dist[to], to});
            }
        }
    }
}

void input(){
    // Если граф задан матрицей смежности    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int d; cin >> d;
            if (d == -1){
                continue;
            } if (i == j){
                continue;
            }

            g[i].push_back({d, j});
        }
    }
}

int main(){

    cin >> n >> s;
    g.resize(n+1);
    visited.resize(n+1);
    dist.resize(n+1, 1e9 /* максимальное расстояние от s до любой другой (гарантируется в условии либо max(веса_ребер) * n) */);

    input();

    dist[s] = 0;
    q.push({dist[s], s});

    bfs();

    return 0;
}
