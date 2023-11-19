#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
using ll = long long;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vu = vector<ull>;

using vvi = vector<vi>;
using vvb = vector<vb>;
using vvl = vector<vl>;
using vvu = vector<vu>;

using pii = pair<int, int>;

const int MAX_SIZE = 1e9+9;

int n, m, k, t;

template <typename T>
void res(vector<T> &v, int n){
    v.resize(n);
}
template <typename T>
void res(vector<vector<T>> &v, int n, int m){
    v.resize(n, vector<T>(m));
}
template <typename T>
void res(vector<T> &v, int n, T val){
    v.resize(n, val);
}
template <typename T>
void res(vector<vector<T>> &v, int n, int m, T val){
    v.resize(n, vector<T>(m, val));
}

/*
 ----- SOLUTION -----
*/
vvi g;
vvb visited;
vector<pii> zero_pos;
vector<vector<char>> answer;

int one, zero;

void dfs(int row, int column, char from){
    if (visited[row][column]) return;

    visited[row][column] = true;
    answer[row][column] = from;
    one--;
    
    if (g[row-1][column] == 1){
        dfs(row-1, column, 'v');
    }
    if (g[row+1][column] == 1){
        dfs(row+1, column, '^');
    }
    if (g[row][column+1] == 1){
        dfs(row, column+1, '<');
    }
    if (g[row][column-1] == 1){
        dfs(row, column-1, '>');
    }
}

bool handle(int row, int column){
    if (g[row-1][column] == 0){
        answer[row][column] = '^';
        return true;
    }
    if (g[row+1][column] == 0){
        answer[row][column] = 'v';
        return true;
    }
    if (g[row][column+1] == 0){
        answer[row][column] = '>';
        return true;
    }
    if (g[row][column-1] == 0){
        answer[row][column] = '<';
        return true;
    }
    return false;
}

void solve(){
    cin >> n; n+=2;
    res(g, n, n, 2);
    res(visited, n, n);
    res(answer, n, n);

    for (int i = 1; i < n-1; i++){
        for (int j = 1; j < n-1; j++){
            char input; cin >> input;
            int el = input - '0';

            if (el == 1){
                one++;
            } else{
                zero++;
                zero_pos.push_back({i, j});
            }
            g[i][j] = el;
        }
    }
    
    for (int i = 1; i < n-1; i++) if (g[1][i] == 1) dfs(1, i, '^');
    for (int i = 1; i < n-1; i++) if (g[n-2][i] == 1) dfs(n-2, i, 'v');
    for (int i = 1; i < n-1; i++) if (g[i][1] == 1) dfs(i, 1, '<');
    for (int i = 1; i < n-1; i++) if (g[i][n-2] == 1) dfs(i, n-2, '>');

    if (one != 0){
        cout << "NO" << '\n';
        return;
    }

    for (auto p : zero_pos){
        int row = p.first, column = p.second;
        if (!handle(row, column)){
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
    for (int i = 1; i < n-1; i++){
        for (int j = 1; j < n-1; j++){
            cout << answer[i][j];
        }
        cout << '\n';
    }
}

void t_solve(){
    cin >> t;
    while(t--){
        solve();
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    solve();

    return 0;
}
