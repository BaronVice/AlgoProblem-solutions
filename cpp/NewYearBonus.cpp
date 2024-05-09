#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define v vector
#define pii pair<int, int>

#define SPEEEED ios_base::sync_with_stdio(0); cin.tie(0);
#define ttest int t; cin >> t; while(t--) solve();

v<v<int>> g;
v<v<int>> dp;
v<int> to_give;
int n;

void dfs(int p){
    if (g[p].size() == 0){
        return;
    }

    int give = 0;
    int dp0_max_diff = 0;
    int dp1_max_diff = 0;
    for (auto el : g[p]){
        dfs(el);
        dp[p][0] += dp[el][1];
        if (dp0_max_diff - dp1_max_diff < dp[el][0] - dp[el][1]){
            give = el;
            dp[p][1] -= dp0_max_diff;
            dp[p][1] += dp1_max_diff + dp[el][0];
            dp0_max_diff = dp[el][0];
            dp1_max_diff = dp[el][1];
        } else {
            dp[p][1] += dp[el][1];
        }
    }

    to_give[p] = give;
}

void solve(){
    cin >> n;
    g.assign(n+1, v<int>());
    dp.assign(n+1, {1, 0});
    to_give.assign(n+1, 0);

    for (int i = 2; i <= n; i++){
        int boss; cin >> boss;
        g[boss].push_back(i);
    }

    dfs(1);
    cout << dp[1][1] << "000" << '\n';
    sort(to_give.begin(), to_give.end());
    for (auto el : to_give) if (el != 0){
        cout << el << ' ';
    }
}

int main(){
    SPEEEED;
    solve();

    return 0;
}
