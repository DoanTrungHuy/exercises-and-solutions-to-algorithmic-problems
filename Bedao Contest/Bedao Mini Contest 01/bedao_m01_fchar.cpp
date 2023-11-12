#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll cnt[26];
ll m;
string s;

bool is_valid() {
    bool flag = true;
    string t = "abcde";
    for (char c : t) {
        if (cnt[c - 'a'] < m) {
            flag = false;
            break;
        }
    }
    return flag;
}

bool is_fchar(ll len) {
    memset(cnt, 0, sizeof(cnt));
    for (ll i = 0, j = 0; i < (int)s.size(); ++i) {
        cnt[s[i] - 'a']++;
        if (i - j + 1 == len) {
            if (is_valid()) {
                return true;
            }
            cnt[s[j++] - 'a']--;
        }
    }
    return false;
}

int main() {
    cin >> s;
    cin >> m;
    ll left = 0, right = s.size() + 1;
    ll ans = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (is_fchar(mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}