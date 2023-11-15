#include <bits/stdc++.h>

using namespace std;
using ll = long long;

double a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(6) << (a / b) / (1 - (1 - a / b)*(1 - c / d));
    return 0;
}