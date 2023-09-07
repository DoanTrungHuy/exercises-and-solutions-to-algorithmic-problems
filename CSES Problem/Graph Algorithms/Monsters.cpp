#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAXN = 1e3 + 1;
string grid[MAXN];
queue<pair<int, int>> mq;
int x_player, y_player;
vector<vector<int>> mat_monsters;

int DIR[5] = {-1, 0, 1, 0, -1};
char op[5] = {'U', 'R', 'D', 'L'};

void bfs_monsters() {
    while (!mq.empty()) {
        int sz = mq.size();

        while (sz--) {
            auto [x, y] = mq.front();
            mq.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + DIR[i];
                int ny = y + DIR[i + 1];

                if (!(0 <= nx and nx < n and 0 <= ny and ny < m)) {
                    continue;
                }

                if (grid[nx][ny] == '#') {
                    continue;
                }

                int new_step = mat_monsters[x][y] + 1;

                if (new_step < mat_monsters[nx][ny]) {
                    mat_monsters[nx][ny] = new_step;
                    mq.push({nx, ny});
                }
            }
        }
    }
}

int trace[MAXN][MAXN];

void bfs_player() {
    int step = 1;
    while (!mq.empty()) {
        int sz = mq.size();

        while (sz--) {
            auto [x, y] = mq.front();
            mq.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + DIR[i];
                int ny = y + DIR[i + 1];

                if (!(0 <= nx and nx < n and 0 <= ny and ny < m)) {
                    string ans;
                    int tx = x, ty = y;
                    while (trace[tx][ty] != -1) {
                        int p = trace[tx][ty];
                        ans.push_back(op[p]);
                        tx -= DIR[p];
                        ty -= DIR[p + 1];
                    }
                    reverse(ans.begin(), ans.end());
                    cout << "YES" << '\n';
                    cout << ans.size() << '\n';
                    cout << ans;
                    return;
                }

                if (grid[nx][ny] == '#') {
                    continue;
                }

                if (step < mat_monsters[nx][ny]) {
                    grid[nx][ny] = '#';
                    trace[nx][ny] = i;
                    mq.push({nx, ny});
                }
            }
        }

        step++;
    }

    cout << "NO";
}

int main() {
    cin >> n >> m;

    mat_monsters.resize(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                x_player = i;
                y_player = j;
            }
            else if (grid[i][j] == 'M') {
                mq.push({i, j});
                mat_monsters[i][j] = 0;
                grid[i][j] = '#';
            }
        }
    }

    bfs_monsters();

    memset(trace, -1, sizeof(trace));
    mq.push({x_player, y_player});
    grid[x_player][y_player] = '#';

    bfs_player();

    return 0;
}