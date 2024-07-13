#include <iostream>

using namespace std;

int t, n;
int ans = (int)1e9;

const int MN = 60;
const int MP = 3;
int vis[MN], per[MN];
int p[MN], c[MN];
int mark_sat[MN];

bool is_valid(int num) {
    return 1 <= num && num <= n;
}

void sort_per(int i, int cost) {
    if (cost > ans) {
        return;
    }

    if (i == MP) {
        ans = min(ans, cost);
        return;
    }

    int num_person = c[per[i]];
    int idx_person = p[per[i]];
    int k = 1;
    int sum = 0;

    if (mark_sat[idx_person] == 0) {
        mark_sat[idx_person] = i + 1;
        sum += 1;
        num_person--;
    }

    while (num_person > 0) {
        int left = idx_person - k;
        int right = idx_person + k;
        if (num_person == 1 && is_valid(left) && is_valid(right) && !mark_sat[left] && !mark_sat[right]) {
            num_person--;
            mark_sat[left] = i + 1;
            sum += 1 + k;
            sort_per(i + 1, cost + sum);
            sum -= 1 + k;
            num_person++;
            mark_sat[left] = 0;

            for (int j = 1; j <= n; ++j) {
                if (i + 1 < mark_sat[j]) {
                    mark_sat[j] = 0;
                }
            }

            num_person--;
            mark_sat[right] = i + 1;
            sum += 1 + k;
            sort_per(i + 1, cost + sum);
            sum -= 1 + k;
            num_person++;
            mark_sat[right] = 0;

            for (int j = 1; j <= n; ++j) {
                if (i + 1 < mark_sat[j]) {
                    mark_sat[j] = 0;
                }
            }
            return;
        }

        if (num_person > 0 && is_valid(left) && !mark_sat[left]) {
            num_person--;
            mark_sat[left] = i + 1;
            sum += 1 + k;
        }

        if (num_person > 0 && is_valid(right) && !mark_sat[right]) {
            num_person--;
            mark_sat[right] = i + 1;
            sum += 1 + k;
        }

        k++;
    }

    sort_per(i + 1, cost + sum);
}

void permutation(int i) {
    if (i == MP) {
        for (int j = 1; j <= n; ++j) {
            mark_sat[j] = 0;
        }
        sort_per(0, 0);
        return;
    }
    for (int j = 0; j < MP; ++j) {
        if (!vis[j]) {
            vis[j] = 1;
            per[i] = j;
            permutation(i + 1);
            vis[j] = 0;
        }
    }
}

int main() {
    // freopen("hugo_di_tau.txt", "r", stdin);
    cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case) {
        cin >> n;
        for (int i = 0; i < MP; ++i) {
            cin >> p[i] >> c[i];
        }
        ans = (int)1e9;
        permutation(0);
        cout << "Case #" << test_case << '\n';
        cout << ans << '\n';
    }
    return 0;
}