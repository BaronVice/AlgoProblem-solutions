#include <iostream>
#include <string>
#include <map>

using namespace std;
using ll = long long;

int const ALPHABET_SIZE = 26;
int const MAXLEN = 1e6 + 100;

struct Node {
    int letters[ALPHABET_SIZE] = { 0 };
    bool isEnd = false;
};

Node trie[MAXLEN];
int trieSize = 1;

int go(int v, char c) {
    return trie[v].letters[c - 'a'];
}

void createTransition(int v, char c) {
    trie[v].letters[c - 'a'] = trieSize++;
}

bool search(const string& s) {
    int v = 0;
    for (char c : s) {
        v = go(v, c);
        if (v == 0)
            return false;
    }

    return trie[v].isEnd;
}

void insert(const string& s) {
    int v = 0;
    for (char c : s) {
        if (go(v, c) == 0) {
            createTransition(v, c);
        }
        v = go(v, c);
    }

    trie[v].isEnd = true;
}

void del(const string& s) {
    int v = 0;
    for (char c : s) {
        v = go(v, c);
        if (v == 0)
            return;
    }

    trie[v].isEnd = false;
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    /* insert("abobus");
    cout << search("abobus") << '\n';
    cout << search("aboba") << '\n';
    insert("aboba");
    cout << search("aboba") << '\n';
    del("aboba");
    cout << search("abobus") << '\n';
    cout << search("aboba") << '\n';

    for (int i = 0; i < 6; i++) {
        for (auto el : trie[i].letters) {
            cout << el << ' ';
        }
        cout << '\n';
    } */

    return 0;
}