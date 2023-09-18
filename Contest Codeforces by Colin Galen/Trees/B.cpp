#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;
const ll MN = 1e5;
vector<ll> adj[MN];
ll c[MN];

int main()
{
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll p;
        cin >> p;
        if (p != -1) {
            p--;
            adj[p].push_back(i);
        }
        cin >> c[i];
    }
    vector<ll> vertex_valid;
    for (ll u = 0; u < n; ++u) {
        if (c[u] == 1) {
            bool flag = false;
            for (ll v : adj[u]) {
                if (c[v] == 0) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                vertex_valid.push_back(u + 1);
            }
        }
    }
    if (vertex_valid.size()) {
        for (ll v : vertex_valid) {
            cout << v << ' ';
        }
    }
    else {
        cout << -1;
    }
    return 0;
}