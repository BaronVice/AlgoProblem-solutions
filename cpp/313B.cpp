#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

int main(){

    string line;
    cin >> line;

    vector<ll> pref(line.size()+1);

    pref[0] = 0;
    for (int i = 0; i < line.size()-1; i++){
        if(line[i] == line[i+1])
            pref[i+1] = pref[i] + 1;
        else
            pref[i+1] = pref[i];
    }

    int m, l, r;
    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> l >> r;
        cout << pref[r-1] - pref[l-1] << endl;
    }


    return 0;

}