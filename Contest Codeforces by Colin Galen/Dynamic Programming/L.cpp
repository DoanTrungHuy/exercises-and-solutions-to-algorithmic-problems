#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, k;
vector<array<ll, 3>> groups;
vector<array<ll, 2>> tables;
const ll MN = 1001;
ll memo[MN][MN], color[MN][MN];
const ll INF = 1e18;

ll dp(ll i, ll j) {
    if (i == n or j == k) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    ll ans = -INF, val = 0;
    ll c = groups[i][0], p = groups[i][1], r = tables[j][0];
    if (c <= r) {
        val = dp(i + 1, j + 1) + p;
        if (ans < val) {
            color[i][j] = 1;
            ans = val;
        }
    }
    val = dp(i + 1, j);
    if (ans < val) {
        color[i][j] = 2;
        ans = val;
    }
    val = dp(i, j + 1);
    if (ans < val) {
        color[i][j] = 3;
        ans = val;
    }
    return memo[i][j] = ans;
}

int main() {
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll c, p;
        cin >> c >> p;
        groups.push_back({c, p, i});
    }
    cin >> k;
    for (ll i = 0; i < k; ++i) {
        ll r;
        cin >> r;
        tables.push_back({r, i});
    }
    sort(groups.begin(), groups.end());
    sort(tables.begin(), tables.end());
    memset(memo, -1, sizeof(memo));
    memset(color, 0, sizeof(color));
    dp(0, 0);
    ll curr_group = 0, curr_table = 0;
    vector<array<ll, 2>> idxs;
    while (curr_group < n or curr_table < k) {
        if (color[curr_group][curr_table] == 1) {
            idxs.push_back({groups[curr_group][2], tables[curr_table][1]});
            curr_group++;
            curr_table++;
        }
        else if (color[curr_group][curr_table] == 2) {
            curr_group++;
        }
        else if (color[curr_group][curr_table] == 3) {
            curr_table++;
        }
        else {
            curr_group++;
            curr_table++;
        }
    }
    cout << idxs.size() << ' ' << memo[0][0] << '\n';
    for (array<ll, 2> idx : idxs) {
        cout << idx[0] + 1 << ' ' << idx[1] + 1 << '\n';
    }
	return 0;
}