#include <bits/stdc++.h>

using namespace std;

const int MAXN = 8;
int mat[MAXN][MAXN];
const int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2};
const int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};

int heuristics(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx and nx < MAXN and 0 <= ny and ny < MAXN) {
            if (mat[nx][ny]) {
                continue;
            }
            cnt++;
        }
    }
    return cnt;
}

using tp = tuple<int, int, int>;

void dfs(int x, int y, int cnt) {
    mat[x][y] = cnt;
    
    if (cnt == 64) {
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    
    priority_queue<tp, vector<tp>, greater<tp>> pq;
    
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx and nx < MAXN and 0 <= ny and ny < MAXN) {
            if (mat[nx][ny]) {
                continue;
            }
            pq.push({heuristics(nx, ny), nx, ny});
        }
    }

    while (!pq.empty()) {
        auto [_, nx, ny] = pq.top();
        pq.pop();
        dfs(nx, ny, cnt + 1);
    }

    mat[x][y] = 0;
}

int main() {
    int x, y;
    cin >> y >> x;
    x--, y--;
    dfs(x, y, 1);
    return 0;
}