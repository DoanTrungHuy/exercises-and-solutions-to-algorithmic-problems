#include <bits/stdc++.h>

using namespace std;

using ll = long long;

map<ll, vector<ll>> mm; 
vector<ll> tmp;

void dfs(ll i, ll s, ll p) {
    if (s > 41) {
        return;
    }
    if (s == 41) {
        if (!mm.count(p) or tmp.size() < mm[p].size()) {
            mm[p] = tmp;
        }
        return;
    }
    for (ll j = i; j <= 41; ++j) {
        tmp.push_back(j);
        dfs(j, s + j, p * j);
        tmp.pop_back();
    }
}

int main() {
    freopen("B1.inp", "r", stdin);
    freopen("B1.out", "w", stdout);
    ll T;
    cin >> T;
    dfs(1, 0, 1);
    for (ll test_case = 1; test_case <= T; ++test_case) {
        ll P;
        cin >> P;
        cout << "Case #" << test_case << ": ";
        if (!mm.count(P)) {
            cout << -1 << '\n';
        }
        else {
            for (ll x : mm[P]) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}