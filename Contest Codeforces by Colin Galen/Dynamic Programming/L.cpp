#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 1e3 + 1;
ll n, k;
pair<ll, ll> groups[MN];
ll r[MN];
ll memo[MN][MN];
const ll INF = 1e18;
ll par[MN][MN];

ll dp(ll i, ll j) {
    if (i == n or j == k) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    ll ans = 0, val = 0;
    if (groups[i].first <= r[j]) {
        val = dp(i + 1, j + 1) + groups[i].second;
        if (ans < val) {
            ans = val;
            par[i][j] = 1;
        }
    }

    val = dp(i + 1, j);
    if (ans < val) {
        ans = val;
        par[i][j] = 2;
    }

    val = dp(i, j + 1);
    if (ans < val) {
        ans = val;
        par[i][j] = 3;
    }

    return memo[i][j] = ans;
}

vector<array<ll, 3>> group_vals;
vector<array<ll, 2>> table_vals;

int main() {
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> groups[i].first >> groups[i].second;
        group_vals.push_back({groups[i].first, groups[i].second, i});
    }

    cin >> k;
    for (ll i = 0; i < k; ++i) {
        cin >> r[i];
        table_vals.push_back({r[i], i});
    }

    sort(groups, groups + n);
    sort(r, r + k);
    sort(group_vals.begin(), group_vals.end());
    sort(table_vals.begin(), table_vals.end());
    memset(memo, -1, sizeof(memo));
    memset(par, 0, sizeof(par));

    dp(0, 0);
    ll curr_group = 0, curr_table = 0;
    vector<pair<ll, ll>> ops;

    while (curr_group < n or curr_table < k) {
        if (par[curr_group][curr_table] == 1) {
            ops.push_back({group_vals[curr_group][2], table_vals[curr_table][1]});
            curr_group++;
            curr_table++;
        }
        else if (par[curr_group][curr_table] == 2) {
            curr_group++;
        }
        else if (par[curr_group][curr_table] == 3) {
            curr_table++;
        }
        else {
            curr_group++;
            curr_table++;
        }
    }

    ll m = ops.size();

    cout << m << ' ' << memo[0][0] << '\n';

    for (ll i = 0; i < m; ++i) {
        cout << ops[i].first + 1 << ' ' << ops[i].second + 1 << '\n';
    }

	return 0;
}