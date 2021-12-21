
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
const int MOD = 1000000007;
int dp[1002][1002], n;
string a[1002];

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) { cin >> a[i]; }
    for (int i = 0; i < 1002; ++i) for (int j = 0 ; j < 1002; ++j) { dp[i][j] = -1; }
    dp[0][0] = (a[0][0] != '*');

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] != -1) { continue; }
            if (a[i][j] == '*') { dp[i][j] = 0; }
            else {
                dp[i][j] = 0;
                if (i > 0 && i <= n) { dp[i][j] += (dp[i - 1][j] % MOD);}
                if (j > 0 && j <= n) { dp[i][j] += (dp[i][j - 1] % MOD);}
                dp[i][j] = dp[i][j] % MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1] << endl;
}