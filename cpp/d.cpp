#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<int> tree(1e7, 0);
vector<int> original(1e7, 0);

void build(int node, int left, int right) {
    if (left + 1 == right) {
        tree[node] = original[left];
        return;
    }
    int m = (left + right) / 2;
    build(node * 2 + 1, left, m);
    build(node * 2 + 2, m, right);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

ll sum(int node, int left, int right, int q_left, int q_right) {
    if (q_right <= left || right <= q_left) {
        return 0;
    }
    if (q_left <= left && right <= q_right) {
        return tree[node];
    }
    int m = (left + right) / 2;
    return sum(2 * node + 1, left, m, q_left, q_right) + sum(2 * node + 2, m, right, q_left, q_right);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; i++)
        original[i] = (s[i] == '(' ? 1 : -1);

    build(0, 0, n); 
    int q;
    cin >> q;
    while (q--) {
        int left, right;
        cin >> left >> right;
        cout << (sum(0, 0, n, left - 1, right) == 0 ? 1 : 0);
    }
}