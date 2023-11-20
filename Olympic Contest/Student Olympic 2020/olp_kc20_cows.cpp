#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, S;

int main() {
    cin >> N >> S;
    cout << N*(N + 1) / 2 - S;
    return 0;
}