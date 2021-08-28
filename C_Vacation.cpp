
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;

//
struct ele {
    i64 a,b,c;
};
i64 n, dp[100010][4];
ele d[100010];

i64 solve2(i64 k, i64 last) {
    if(k == n) return 0;
    if(dp[k][last] != -1) return dp[k][last];
    i64 cnt = INT_MIN;
    if(last == 0) {
        cnt = max(cnt, d[k].a + solve2(k + 1, 1));
        cnt = max(cnt, d[k].b + solve2(k + 1, 2));
        cnt = max(cnt, d[k].c + solve2(k + 1, 3));
    }
    if(last == 1) {
        cnt = max(cnt, d[k].b + solve2(k + 1, 2));
        cnt = max(cnt, d[k].c + solve2(k + 1, 3));
    }
    if(last == 2) {
        cnt = max(cnt, d[k].a + solve2(k + 1, 1));
        cnt = max(cnt, d[k].c + solve2(k + 1, 3));
    }
    if(last == 3) {
        cnt = max(cnt, d[k].a + solve2(k + 1, 1));
        cnt = max(cnt, d[k].b + solve2(k + 1, 2));
    }
    return dp[k][last] = cnt;
}
void solve(){
    cin >> n;
    for (i64 i = 0; i < n; i++) cin >> d[i].a >> d[i].b >> d[i].c;
    memset(dp, -1, sizeof(dp));
    cout << solve2(0, 0);
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}


