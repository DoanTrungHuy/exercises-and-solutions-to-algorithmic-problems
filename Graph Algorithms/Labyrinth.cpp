#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
string s[MAXN];
int n, m;
bool visited[MAXN][MAXN];
int DIR[5] = {0, -1, 0, 1, 0};
char op[5] = {'L', 'U', 'R', 'D'};

int main()
{
    memset(visited, false, sizeof(visited));

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    int cnt = 0;
    queue<pair<int, int>> mq;
    pair<int, int> coorA, coorB;

    int trance[n][m];
    memset(trance, -1, sizeof(trance));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'A') {
                coorA = {i, j};
                mq.push(coorA);
                visited[i][j] = true;
            }
            else if (s[i][j] == 'B') {
                coorB = {i, j};
            }
        }
    }

    while (!mq.empty()) {
        auto [x, y] = mq.front();
        mq.pop();

        if (x == coorB.first and y == coorB.second) {
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + DIR[i];
            int ny = y + DIR[i + 1];

            if (0 <= nx and nx < n and 0 <= ny and ny < m and !visited[nx][ny]) {
                if (s[nx][ny] == '#') {
                    continue;
                }
                mq.push({ nx, ny });
                visited[nx][ny] = true;
                trance[nx][ny] = i;
            }
        }
    }

    if (visited[coorB.first][coorB.second]) {
        cout << "YES" << '\n';
        string path;
        while (coorB != coorA) {
            auto [x, y] = coorB;
            int i = trance[x][y];
            path.push_back(op[i]);
            int nx = x - DIR[i];
            int ny = y - DIR[i + 1];
            coorB = { nx, ny };
        }
        cout << path.size() << '\n';
        cout << string(path.rbegin(), path.rend());
    }
    else {
        cout << "NO";
    }
    
    return 0;
}