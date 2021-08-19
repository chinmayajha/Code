
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
    int n,m;cin >> n >> m;
    vector<int> a(n),b(m);
    inarr(a,n);inarr(b,m);
    sort(all(a));sort(all(b));
    int mn = INT_MAX;
    for(auto& i : a){
        int temp = lower_bound(all(b),i) - b.begin();
        if(temp < m)mn = min(mn,abs(i - b[temp]));
    }
    for(auto& i : b){
        int temp = lower_bound(all(a),i) - a.begin();
        if(temp < n)mn = min(mn,abs(i - a[temp]));
    }
    if(mn == INT_MAX){
        cout << min(abs(a[0]-b[m-1]),abs(a[n-1]-b[0]));
    } else cout << mn;
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}


