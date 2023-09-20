#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll t;

int main()
{
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        queue<ll> mq[2];
        for (char c : s) {
            if ((c - '0') % 2) {
                mq[0].push(c);
            }
            else {
                mq[1].push(c);
            }
        }
        string v;
        while (!mq[0].empty() or !mq[1].empty()) {
            if (!mq[0].empty() and mq[0].front() < mq[1].front()) {
                v.push_back(mq[0].front());
                mq[0].pop();
            }
            else if (!mq[1].empty() and mq[1].front() < mq[0].front()) {
                v.push_back(mq[1].front());
                mq[1].pop();
            }
            else if (!mq[0].empty()) {
                v.push_back(mq[0].front());
                mq[0].pop();
            }
            else {
                v.push_back(mq[1].front());
                mq[1].pop();
            }
        }
        cout << v << '\n';
    }
    return 0;
}