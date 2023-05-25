#include "bits/stdc++.h"
using namespace std;
#define int long long

// Create matrix, leaft leaned triangle and not pyramid shaped
// prefix sum each column => pref
// find i, j of given N
// start from target i, j and 
// output sum of pref[i][j] diagonally towards the top left doing i--, j-- every step

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;

    vector<vector<int>> a(2023, vector<int>(2000, 0));
    auto pref = a;
    int lim = 1, cur = 1;
    for(int i = 0; i < 2023; ++i) {
        int temp = lim;
        for(int j = 0; j < 2000 && temp > 0; ++j) {
            temp--;
            a[i][j] = pref[i][j] = cur * cur;
            if(i > 0) pref[i][j] += pref[i - 1][j];
            cur++;
        }
        lim++;
    }

    vector<int> to_search(2000);
    for(int i = 1; i <= 2000; ++i) {
        to_search[i - 1] = i * (i - 1) / 2 + 1;
    }

    while (t--) {
        int n, ans = 0; cin >> n;
        int row = upper_bound(to_search.begin(), to_search.end(), n) - to_search.begin() - 1;
        int column = n - to_search[row];
        for(int i = row, j = column; i >= 0 && j >= 0; i--, j--) {
            ans += pref[i][j];
            if(j == 0) break;
        }
        cout << ans << "\n";
    }
}
