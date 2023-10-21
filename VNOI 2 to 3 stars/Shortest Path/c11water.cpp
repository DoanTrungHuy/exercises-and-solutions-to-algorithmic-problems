#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class Solution {
public:
    ll trapRainWater(vector<vector<ll>>& grid) {
        using tp = tuple<ll, ll, ll>;
        priority_queue<tp, vector<tp>, greater<tp>> pq;
        const ll n = grid.size();
        const ll m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < m; ++j) {
                if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
                    pq.push({grid[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        ll dx[4] = {-1, 1, 0, 0};
        ll dy[4] = {0, 0, -1, 1};
        
        ll total = 0;
        
        while (!pq.empty()) {
            auto [curr_height, x, y] = pq.top();
            pq.pop();
            
            for (ll i = 0; i < 4; ++i) {
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                if (!(0 <= nx and nx < n and 0 <= ny and ny < m)) {
                    continue;
                }
                if (visited[nx][ny]) {
                    continue;
                }
                if (grid[nx][ny] < curr_height) {
                    total += curr_height - grid[nx][ny];
                    pq.push({curr_height, nx, ny});
                }
                else {
                    pq.push({grid[nx][ny], nx, ny});
                }
                visited[nx][ny] = true;
            }
        }
        
        return total;
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    cout << Solution().trapRainWater(grid);
    return 0;
}