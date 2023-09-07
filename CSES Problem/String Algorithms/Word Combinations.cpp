#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    TrieNode *child[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
        isWord = false;
    }
};

struct Trie {
    TrieNode *root = new TrieNode();

    void insert(string word) {
        TrieNode *curr = root;

        for (char c : word) {
            if (curr->child[c - 'a'] == nullptr) {
                curr->child[c - 'a'] = new TrieNode();
            }
            curr = curr->child[c - 'a'];
        }

        curr->isWord = true;
    }
};

string s;
int n;
const int MOD = 1e9 + 7;
Trie tn;
int memo[5001];
int m;

int dp(int i) {
    if (i == m) {
        return 1;
    }
    if (memo[i] != -1) {
        return memo[i];
    }

    TrieNode *curr = tn.root;

    int ans = 0;

    for (int j = i; j < m; ++j) {
        if (curr->child[s[j] - 'a'] != nullptr) {
            curr = curr->child[s[j] - 'a'];
        }
        else {
            break;
        }
        if (curr->isWord) {
            ans = (ans + dp(j + 1)) % MOD;
        }
    }

    return memo[i] = ans;
}

int main() {
    cin >> s;
    m = s.size();

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        string t;
        cin >> t;
        tn.insert(t);
    }

    memset(memo, -1, sizeof(memo));

    cout << dp(0);

    return 0;
}