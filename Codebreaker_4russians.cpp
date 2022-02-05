// https://codebreaker.xyz/problem/4russians

#include "bits/stdc++.h"
using namespace std;
#define int long long
#define push_back pb

int n, k;
vector<int> cat, smurf;

void solve() {
    for(int i = 1; i <= n + 1; ++i) smurf[i] += smurf[i - 1];
    
}

void preprocess() {
    int check_for_ci_0 = 1; // subtask 3
    for(int i = 1; i <= n; ++i) {
        cin >> cat[i];
        if(cat[i] != 0) check_for_ci_0 = 0;
    }
    for(int i = 1; i <= n; ++i) cin >> smurf[i];
    if(check_for_ci_0) {
        sort(smurf.rbegin(), smurf.rend());
        for(int i = 1; i < k; ++i) smurf[0] += smurf[i];
        cout << smurf[0];
        exit(0);
    }
    if(k == 1) {
        // subtask 2
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans = max(ans, smurf[i] - (cat[i] * cat[i - 1] + cat[i] * cat[i + 1]));
        }
        cout << ans;
        exit(0);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    cat.assign(n + 2, 0);
    smurf.assign(n + 2, 0);
    preprocess();
    solve();
}