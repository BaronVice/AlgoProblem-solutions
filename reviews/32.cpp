#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct road {
    int to;
    int d;
    int limit;
};

// Функция сравнения (компаратор) для элементов priority_queue
struct compare {
   bool operator()(const pii& l, const pii& r){
        // В очередь закидываем pii, pii.first - дистанция, pii.second - вершина, в которую идем
        // Чем меньше дистанция, тем первее в очереди будет пара
        return l.first > r.first;
    }  
};  

// Количество вершин и стартовая
int n, m, l = 0, r = 1e7+1;
// Граф
vector<vector<road>> g;
// Посещенные
vector<bool> visited;
// Кратчайшие расстояния от s до dist[i]
vector<int> dist;
// Как и в bfs, будем закидывать сюда вершины, но приоритет отдаем с меньшим расстоянием (first - вес, second - номер вершины)
// compare - функция по которой определяется приоритет (здесь чем меньше значение - тем выше приоритет)
priority_queue<pii, vector<pii>, compare> q;

void roll_back(){
    for (int i = 0; i <= n; i++){
        dist[i] = 1e9;
        visited[i] = false;
    }
}

bool good(int mid){
    roll_back();

    mid *= 100;
    mid += 3000000;
    // cout << mid << '\n';

    dist[1] = 0;
    q.push({0, 1});

    while (!q.empty()){
        int v = q.top().second;
        q.pop();

        if (visited[v])
            continue;
        
        visited[v] = true;

        for (auto & p : g[v]) if (p.limit >= mid){
            int to = p.to;
            int d = p.d;

            // Если от текущей могу перейти в соседнюю и улучшить ее расстояние
            if (dist[v] + d < dist[to]){
                // То улучшаю расстояние соседней вершины и закидываю ее на рассмотрение
                dist[to] = dist[v] + d;
                q.push({dist[to], to});
            }
        }
    }

    return dist[n] <= 1440;
}

void bin_search(){
    while(l+1 < r){
        int mid = (l+r) / 2;

        if (good(mid)){
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l;
}

void input(){
    for (int i = 1; i <= m; i++){
        int from, to, d, limit; cin >> from >> to >> d >> limit;
        g[from].push_back({to, d, limit});
        g[to].push_back({from, d, limit});
    }  
}

int main(){

    cin >> n >> m;
    g.resize(n+1);
    visited.resize(n+1);
    dist.resize(n+1, 1e9 /* максимальное расстояние от s до любой другой (гарантируется в условии либо max(веса_ребер) * n) */);

    input();
    bin_search();

    // cout << '\n';
    // for (auto d : dist){
    //     cout << d << ' ';
    // }

    return 0;
}
