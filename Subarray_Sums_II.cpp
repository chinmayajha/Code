
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    i64 n, k, sum = 0, cnt = 0;
    cin >> n >> k;
    vector<i64> a(n);
    map<i64, int> mp;
    mp[0]++;
    generate_n(a.begin(), n, nxt);
    for(int i = 0;i < n; ++i) {
        sum += a[i];
        cnt += mp[sum - k];
        mp[sum]++;
    }
    cout << cnt;

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


