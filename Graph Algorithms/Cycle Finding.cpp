#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAXN = 2501;
using ll = long long;
using tp = tuple<int, int, ll>;
vector<tp> edges;
const ll inf = 1e15;

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w * 1LL});
    }

    vector<ll> dist(n + 1, inf);
    dist[1] = 0;
    vector<int> trace(n + 1, -1);

    int p = 0;

    for (int i = 1; i <= n; ++i)
    {
        p = 0;
        for (auto [a, b, w] : edges)
        {
            if (dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                trace[b] = a;
                p = b;
            }
        }
    }

    if (p == 0) {
        cout << "NO";
    }
    else {
        cout << "YES" << '\n';

        vector<int> ans;

        for (int i = 1; i <= n; ++i) {
            p = trace[p];
        }

        ans.push_back(p);

        int t = p;

        while (trace[t] != p) {
            t = trace[t];
            ans.push_back(t);
        }

        ans.push_back(p);

        reverse(ans.begin(), ans.end());

        for (int x : ans) {
            cout << x << ' ';
        }
    }

    return 0;
}