#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

int main(){

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, w;
    cin >> n >> w;

    vector<int> cost(n+1);
    vector<int> weight(n+1);
    vector<vector<ull>> memo(n+1, vector<ull>(w+1, 0));

    for (int i = 1; i <= n; i++)
        cin >> weight[i] >> cost[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= w; j++){
            if (weight[i] <= j)
                memo[i][j] = max(memo[i-1][j], cost[i] + memo[i-1][j-weight[i]]);
            else
                memo[i][j] = memo[i-1][j];
        }
    
    cout << memo[n][w] << '\n';

    return 0;
}