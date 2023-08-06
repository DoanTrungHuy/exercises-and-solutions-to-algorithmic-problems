#include <bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
int main()
{
    int n, q;
    
    cin >> n >> q;
    
    int p[n + 1];
    
    using pii = pair<int, int>;
    ordered_set<pii> os;
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        os.insert({p[i], i});
    }
    
    while (q--) {
        char t;
        cin >> t;
        if (t == '!') {
            int k, x;
            cin >> k >> x;
            os.erase(os.lower_bound({p[k], k}));
            p[k] = x;
            os.insert({p[k], k});
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << os.order_of_key({b, INT_MAX}) - os.order_of_key({a - 1, INT_MAX}) << "\n";
        }
    }
    
    return 0;
}