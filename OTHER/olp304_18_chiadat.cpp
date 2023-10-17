#include <bits/stdc++.h>

using namespace std;

const int MN = 505;
int pref[MN][MN];
int n;

int query(int x1, int y1, int x2, int y2) {
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}

int main()
{
    freopen("CHIADAT.INP", "r", stdin);
    freopen("CHIADAT.OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(pref, 0, sizeof(pref));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = 0; j < n; ++j) {
            int val;
            cin >> val;
            s += val;
            pref[i + 1][j + 1] = s + pref[i][j + 1];
        }
    }
    int min_diff = INT_MAX;
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = 1; j <= n - 1; ++j) {
            vector<tuple<int, int, int, int>> DIR = {
                {1, 1, i, j},
                {i + 1, j + 1, n, n},
                {1, j + 1, i, n},
                {i + 1, 1, n, j}
            };
            int min_ele = INT_MAX;
            int max_ele = INT_MIN;
            for (auto [x1, y1, x2, y2] : DIR) {
                min_ele = min(min_ele, query(x1, y1, x2, y2));
                max_ele = max(max_ele, query(x1, y1, x2, y2));
            }
            min_diff = min(min_diff, max_ele - min_ele);
        }
    }
    cout << min_diff;
    return 0;
}