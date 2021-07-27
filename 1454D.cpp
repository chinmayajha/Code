
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    i64 n;cin >> n;
    vector<pair<i64,i64>> a;    
    // PRIME FACTORIZATION
    for (i64 i = 2; i*i <= n; i++){
        i64 cnt = 0;
        while (n % i == 0){
            cnt++;
            n = n/i;
        }
        if(cnt)a.emplace_back(make_pair(cnt,i));
    }
    if(n>1)a.emplace_back(make_pair(1,n));
    sort(rall(a));
    //
    vector<i64> ans(a[0].first,a[0].second);
    for(int i=1;i<sz(a);++i)for(int j=0;j<a[i].first;++j)
            ans.back() *= a[i].second;
        
    
    cout << sz(ans) << "\n";
    for(auto& i : ans) cout << i << " ";
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }
}
