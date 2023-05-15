#include <iostream>
#include <vector>
#include <string>


using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> original;
vector<vector<int>> fenvic;

void inc(int row, int col, int value) {
    int i = row;
    int j = col;
    while (i < n) {
        while (j < m) {
            fenvic[i][j] += value;
            j = j | (j + 1);
        }
        i = i | (i + 1);
    }
}

void buildFenvic() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            inc(i, j, original[i][j]);
}

ll sum(int x, int y) {
    int i = x - 1;
    int j = y - 1;
    ll result = 0;
    while (i >= 0) {
        while (j >= 0) {
            result += fenvic[i][j];
            j = (j & (j + 1)) - 1;
        }
        i = (i & (i + 1)) - 1;
    }

    return result;
}

ll sum(int x1, int y1, int x2, int y2) {
    return sum(x1, y1) - sum(x2 - 1, y2 - 1);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    original.resize(n);
    fenvic.resize(n);

    for (int i = 0; i < n; i++) {
        original[i].resize(m);
        fenvic[i].resize(m);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> original[i][j];

    buildFenvic();
    // for(auto row : fenvic){
    //     for (auto el : row)
    //         cout << el << ' ';
    //     cout << '\n';
    // }

    return 0;
}