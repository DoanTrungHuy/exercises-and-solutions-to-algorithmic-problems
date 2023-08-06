#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int MAXN = 2e5 + 5;
int x[MAXN];
int n, q;
 
int main()
{
    cin >> n >> q;
    
    int p[n + 1] = {};
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        p[i] = p[i - 1] ^ x[i];
    }
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (p[b] ^ p[a - 1]) << '\n';
    }
    
    return 0;
}