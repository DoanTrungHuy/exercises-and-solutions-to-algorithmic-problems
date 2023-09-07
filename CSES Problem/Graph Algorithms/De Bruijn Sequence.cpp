#include <bits/stdc++.h>

using namespace std;

int n;
string ans;
unordered_set<string> visited;
int total_way = 0;

bool dfs(string window) {
    if ((int)visited.size() == total_way) {
        return true;
    }
    for (int i = 0; i < 2; ++i) {
        char c = i + '0';
        string new_window = window + c;
        if (!visited.count(new_window)) {
            visited.insert(new_window);
            ans.push_back(c);
            if (dfs(new_window.substr(1))) {
                return true;
            }
            visited.erase(new_window);
            ans.pop_back();
        }
    }
    return false;
}

int main() {
    cin >> n;

    string window = "";

    for (int i = 0; i < n - 1; ++i) {
        window.push_back('0');
    }

    ans = window;

    total_way = pow(2, n);

    dfs(window);
    cout << ans;

    return 0;
}