
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
#define dbg(x) cerr << #x <<" = " << x << "\n";
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    generate_n(a.begin(), n, nxt);
    int ans = 1;
    int diff, pdiff = 0, l = 0, r = 0;
    for(int i=1;i<n;++i){
        diff = a[i] - a[i-1];
        if(diff){
            if(diff == pdiff){
                r = l + 1;
            }
            l = i - 1;
            pdiff = diff;
        }
        ans = max(ans, i - r + 1);
    }
    cout << ans;

}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 0; i < testt; ++i) solve();
}


