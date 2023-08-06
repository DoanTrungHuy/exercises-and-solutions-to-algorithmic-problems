#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
string s[MAXN];
int n, m;
bool visited[MAXN][MAXN];
int DIR[5] = {0, -1, 0, 1, 0};

int dfs(int i, int j) {
    if (!(0 <= i and i < n and 0 <= j and j < m)) {
        return 0;
    }
    if (s[i][j] == '#') {
        return 0;
    }
    if (visited[i][j]) {
        return 0;
    }
    visited[i][j] = true;
    int cnt = 1;
    for (int d = 0; d < 4; ++d) {
        cnt += dfs(i + DIR[d], j + DIR[d + 1]);
    }
    return cnt;
}

int main()
{
    memset(visited, false, sizeof(visited));
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                cnt += dfs(i, j) > 0;
            }
        }
    }
    cout << cnt;

    return 0;
}