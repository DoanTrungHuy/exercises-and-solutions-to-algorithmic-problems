#include <iostream>
 
using namespace std;
using ll = long long;
 
const int MAXN = 2e5 + 5;
ll b[MAXN] = {};
int n, q;
 
void update(int i, ll v) {
    for (; i <= n; i += i&-i) {
        b[i] += v;
    }
}
 
ll getSum(int i) {
    ll res = 0;
    for (; i > 0; i -= i&-i) {
        res += b[i];
    }
    return res;
}
 
int main()
{
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        update(i, x);
    }
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << getSum(b) - getSum(a - 1) << '\n';
    }
    
    return 0;
}