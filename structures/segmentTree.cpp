#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int n, nPowered;
vector<int> tree;
vector<int> original;
vector<int> propagation;


int highestPow(int n)
{
    int p = (int)log2(n-1);
    return (int)pow(2, p) * 2;
}


void buildTree(int node, int left, int right) {

    if (right - left == 1) {
        tree[node] = original[left];
        return;
    }

    int mid = (left + right) / 2;
    buildTree(2 * node, left, mid);
    buildTree(2 * node + 1, mid, right);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}


void propagate(int node) {
    if (node * 2 + 1 < 2 * nPowered) {
        propagation[node * 2 + 1] *= propagation[node];
        propagation[node * 2] *= propagation[node];
    }

    tree[node] *= propagation[node];
    propagation[node] = 1;
}


void update(int node, int left, int right, int q_left, int q_right, int value) {
    propagate(node);
    if (q_left <= left && right <= q_right) {
        propagation[node] *= value;
        return;
    }
        
    if (right <= q_left || left >= q_right)
        return;

    int mid = (right + left) / 2;
    update(2 * node, left, mid, q_left, q_right, value);
    update(2 * node + 1, mid, right, q_left, q_right, value);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}


int findSum(int node, int left, int right, int q_left, int q_right) {
    propagate(node);
    if (q_left <= left && right <= q_right)
        return tree[node];
    if (right <= q_left || left >= q_right)
        return 0;

    int mid = (right + left) / 2;
    int r = findSum(2 * node, left, mid, q_left, q_right);
    int l = findSum(2 * node + 1, mid, right, q_left, q_right);

    return r + l;
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    nPowered = highestPow(n);

    tree.resize(2 * nPowered, 0);
    propagation.resize(2 * nPowered, 1);
    original.resize(nPowered, 0);

    for (int i = 0; i < n; i++)
        cin >> original[i];

    buildTree(1, 0, nPowered);

    update(1, 0, nPowered, 0, 2, 2);
    cout << findSum(1, 0, nPowered, 0, 1) << '\n';

    for (auto el : propagation)
        cout << el << '\n';

    return 0;
}