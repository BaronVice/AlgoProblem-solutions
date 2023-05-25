#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int const ALPHABET_SIZE = 26;
int const MAXLEN = 1e6 + 100;

vector<vector<pii>> tree;
vector<int> edges;
bool isPossible;
int answer;

int dfs(int point, int parrent, int edge) {
    if (!isPossible)
        return 0;

    int res = 0;

    for (auto child : tree[point]) {
        if (child.first != parrent)
            res += dfs(child.first, point, child.second);
    }

    if (res > 3) {
        isPossible = false;
        return 0;
    }
    if (res == 2) {
        answer++;
        edges.push_back(edge);
        return 0;
    }
    
    return res + 1;
    
}

void solve() {
    int n;
    cin >> n;
    tree.clear();
    tree.resize(n+1);
    edges.clear();
    answer = 0;
    isPossible = true;

    int from, to;
    for (int i = 1; i < n; i++) {
        cin >> from >> to;
        tree[from].push_back({ to, i });
        tree[to].push_back({ from, i });
    }

    int last_point = dfs(from, -1, -1);

    if (!isPossible || last_point != 0)
        cout << -1 << '\n';
    else {
        cout << answer - 1 << '\n';
        edges.pop_back();
        for (auto edge : edges)
            cout << edge << ' ';
        cout << '\n';
    }
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}