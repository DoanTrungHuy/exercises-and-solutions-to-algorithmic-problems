#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N;
const ll MN = 5e3 + 100;
const ll MOD = 1e9 + 7;
string s;
ll a[MN];

struct TrieNode {
    bool is_word;
    TrieNode *child[26];

    TrieNode() {
        is_word = false;
        for (ll i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
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

        curr->is_word = true;
    }
};

Trie te;
ll memo[MN];

ll dp(ll i) {
    if (i == s.size()) {
        return 1;
    }
    if (memo[i] != -1) {
        return memo[i];
    }
    TrieNode *curr = te.root;
    ll ans = 0;
    for (ll j = i; j < s.size(); ++j) {
        if (curr->child[s[j] - 'a']) {
            curr = curr->child[s[j] - 'a'];
        }
        else {
            break;
        }
        if (curr->is_word) {
            (ans += dp(j + 1)) %= MOD;
        }
    }
    return memo[i] = ans;
}

int main() {
    cin >> s >> N;
    for (ll i = 0; i < N; ++i) {
        string word;
        cin >> word;
        te.insert(word);
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0);
    return 0;
}