#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define v vector
#define pii pair<int, int>

#define SPEEEED ios_base::sync_with_stdio(0); cin.tie(0);
#define ttest int t; cin >> t; while(t--) solve();

bool TSOLVE = false;

int n;

v<v<int>> g;
v<int> dfs1;
v<int> dfs2;
v<int> dfs3;

void dfs(int to, int from, int val, v<int>& dfsn){
    dfsn[to] = val;
    for (auto el : g[to]) if (el != from){
        dfs(el, to, val + 1, dfsn);
    }
} 

void solve(){
    cin >> n;
    g.assign(n+1, vector<int>());
    dfs1.assign(n+1, 0);
    dfs2.assign(n+1, 0);
    dfs3.assign(n+1, 0);
    
    // Потому что вершины дают с 2 номера
    // for (int i = 1; i < n; i++) {
    for (int i = 2; i <= n; i++){
        int from; cin >> from;
        g[from].push_back(i);
        g[i].push_back(from);
    }
    
    // Ищем самую отдаленной от текущей
    dfs(1, 0, 0, dfs1);
    int m = 0;
    int firstp = 0;
    // for (int i = 1; i < n; i++){
    for (int i = 1; i <= n; i++){
        if (m < dfs1[i]) { firstp = i; m = dfs1[i]; }
    }

    // Ищем самую отдаленную от первой отдаленной
    dfs(firstp, 0, 0, dfs2);
    m = 0;
    int lastp = 0;
    for (int i = 1; i <= n; i++){
        // lastp - вершины, m - расстояние
        if (/*lastp*/m < dfs2[i]) { lastp = i; m = dfs2[i]; }
    }
    
    // dfs(firstp,lastp,0,dfs3);
    // От второй удаленной записывем в dfs3
    dfs(lastp, 0, 0, dfs3);
    
    for (int i = 1; i <= n; i++) {
        if(m % 2 == 0) {
            if(dfs2[i] == m / 2 && dfs3[i] == m / 2)
            { cout << i << ' '; } 
        }
        else {
            if (
                (dfs2[i] == m / 2 + 1 && dfs3[i] == m / 2) || (dfs3[i] == m / 2 + 1 && dfs2[i] == m / 2)
                )/*;*/ cout << i << ' ';
        }
    }
}

int main(){
    SPEEEED;
    if (TSOLVE){
        ttest;
    } else {
        solve();
    }
    return 0;
}
