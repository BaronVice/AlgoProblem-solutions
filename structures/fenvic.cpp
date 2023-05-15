#include <iostream>
#include <vector>
#include <string>


using namespace std;
using ll = long long;

    int n, m;
    vector<int> original;
    vector<int> fenvic;

void inc(int i, int value){
    int j = i;
    while (j < n){
        fenvic[j] += value;
        j = j | (j + 1);
    }
}

void buildFenvic(){
    for (int i = 0; i < n; i++)
        inc(i, original[i]);
}

ll sum(int r){
    int i = r-1;
    ll result = 0;
    while (i >= 0){
        result += fenvic[i];
        i = (i & (i+1)) - 1;
    }

    return result;
}

ll sum(int l, int r){
    return sum(r) - sum(l-1);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    original.resize(n);
    fenvic.resize(n);

    for (int i = 0; i < n; i++)
        cin >> original[i];

    buildFenvic();
    // for(auto el : fenvic)
    //     cout << el << '\n';

    return 0;
}