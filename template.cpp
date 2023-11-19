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
vvi g;
vvb visited;

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

void solve(){
    
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
