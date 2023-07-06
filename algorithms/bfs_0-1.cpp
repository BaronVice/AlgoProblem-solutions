#include <iostream>
#include <vector>
#include <deque>

using namespace std;
using ll = long long;

struct Node{
    int to, weight;
};

int n, s;
vector<vector<Node>> g;
vector<int> dist;
deque<int> q;

void bfs(){
    while (!q.empty()){
        int v = q.front();
        q.pop_front();

        for (auto el : g[v]){
            if (dist[el.to] > dist[v] + el.weight){
                dist[el.to] = dist[v] + el.weight;

                if (el.weight == 0)
                    q.push_front(el.to);
                else
                    q.push_back(el.to);
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
    q.push_back(s);

    bfs();

    return 0;
}