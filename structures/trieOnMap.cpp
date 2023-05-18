#include <iostream>
#include <string>
#include <map>

using namespace std;
using ll = long long;

int const ALPHABET_SIZE = 26;
int const MAXLEN = 1e6 + 100;

struct Node {
    map<char, int> letters;
    bool isEnd = false;
};

Node trie[MAXLEN];
int trieSize = 1;

// go(v, c) == 0 is kinda bad as map will initialize default value
bool isExists(int v, char c) {
    return trie[v].letters.count(c);
}

int go(int v, char c) {
    return trie[v].letters[c];
}

void createTransition(int v, char c) {
    trie[v].letters[c] = trieSize++;
}

bool search(const string& s) {
    int v = 0;
    for (char c : s) {
        if (!isExists(v, c))
            return false;

        v = go(v, c);
    }

    return trie[v].isEnd;
}

void insert(const string& s) {
    int v = 0;
    for (char c : s) {
        if (!isExists(v, c))
            createTransition(v, c);
        
        v = go(v, c);
    }

    trie[v].isEnd = true;
}

void del(const string& s) {
    int v = 0;
    for (char c : s) {
        if (!isExists(v, c))
            return;
        v = go(v, c);
    }

    trie[v].isEnd = false;
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    insert("abobus");
    cout << search("abobus") << '\n';
    cout << search("aboba") << '\n';
    insert("aboba");
    cout << search("aboba") << '\n';
    del("aboba");
    cout << search("abobus") << '\n';
    cout << search("aboba") << '\n';

    /* for (int i = 0; i < 6; i++) {
        for (auto el : trie[i].letters) {
            cout << el << ' ';
        }
        cout << '\n';
    } */

    return 0;
}