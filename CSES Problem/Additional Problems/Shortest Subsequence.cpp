#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N;
const ll MN = 1e5 + 100;
ll a[MN];

int main() {
    string s;
    cin >> s;
    unordered_map<char, bool> um;
    string res = "";
    for (ll i = 0; i < (ll)s.size(); ++i) {
        um[s[i]] |= true;
        if (um['A'] and um['C'] and um['G'] and um['T']) {
            um['A'] = false;
            um['C'] = false;
            um['G'] = false;
            um['T'] = false;
            res += s[i];
        }
    }
    for (const auto &[chr, chk] : um) {
        if (!chk) {
            res += chr;
            break;
        }
    }
    cout << res;
    return 0;
}