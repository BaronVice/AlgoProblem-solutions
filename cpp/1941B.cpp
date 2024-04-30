// https://codeforces.com/contest/1941/problem/B

#include <bits/stdc++.h>

using namespace std;

string solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    for (int i = 1; i < n-1; i++){
        v[i] -= v[i-1] * 2;
        v[i+1] -= v[i-1];
        v[i-1] = 0;
        if (v[i] < 0) return "NO"; 
    }
    for (auto el : v){
        if (el != 0) return "NO";
    }
    return "YES";
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        cout << solve() << '\n';

    return 0;
}
