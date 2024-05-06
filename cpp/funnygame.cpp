// https://contest.yandex.ru/contest/58807/problems/33/?success=113602130#7/2020_01_11/LUqv0wKkNA

#include <bits/stdc++.h>
using namespace std;

#define SPEEEED ios_base::sync_with_stdio(0); cin.tie(0);
#define ttest int t; cin >> t; while(t--) solve();
#define v vector
#define pii pair<int, int>

// Граф
v<v<int>> g;
// Кто выигрывает в dp[i] аэропорте
v<bool> dp;

int n, k; 

// Текущий номер аэропорта, откуда прилители, текущий игрок
void dfs(int point, int last, bool player) {
    // Пока что говорим, что текущий игрок проигрывает в этом аэропорте
    bool p = !player;
    for(auto c: g[point]){
        if(c != last){
            dfs(c, point, !player);
            // Но если найдется такой аэропорт, что он выиграет, то и в текущем аэропорте он выигрывает
            if(dp[c] == player) p = player;
        }
    }
    // Записываем, кто выиграет в этом аэропорте
    dp[point] = p;
}

void solve(){
    cin >> n >> k;
    g.resize(n+1);
    dp.resize(n+1);

    int m = n-1;
    while(m--){
        int from, to; cin >> from >> to;
        g[to].push_back(from);
        g[from].push_back(to);
    }

    // Поскольку игроков два, то скажем 0(false) - первый игрок, 1(true) - второй игрок
    dfs(k, 0, 0);
    if (dp[k] == true){
        cout << "First player loses" << '\n';
    } else {
        // Поскольку по условию просят наименьший номер, то делаем sort
        sort(g[k].begin(), g[k].end());
        // Ищем первый подходящий аэропорт
        for (auto el : g[k]) if (dp[el] == false){
            cout << "First player wins flying to airport " << el << '\n';
            break;
        }
    }
}

int main(){
    SPEEEED;
    solve();    
    
    return 0;
}
