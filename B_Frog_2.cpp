
    #include "bits/stdc++.h"
    #pragma GCC optimize "trapv"
    using i64 = long long int;
    using namespace std;
    int nxt(){int x; cin >> x; return x;}
    #define sz(x) ((int)(x).size()) 
    #define all(x) (x).begin(), (x).end()
    #define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
    //
    int n, k, a[100010], dp[100010];
    int solve2(int m){
        if(m >= n - 1) return 0;
        if(dp[m] != -1) return dp[m];
        int cnt = INT_MAX;
        for(int i = 1;i <= k; ++i){
            if(m + i < n) cnt = min(cnt, abs(a[m] - a[m + i]) + solve2(m + i));
        }
        return dp[m] = cnt;

    }
    void solve(){
        cin >> n >> k; inarr(a, n);
        memset(dp, -1, sizeof(dp));
        cout << solve2(0);
    }

    int main(){
        cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
        int testt = 1;
        // cin >> testt;
        for (int i = 1; i <= testt; ++i){
            solve();
        }
    }


