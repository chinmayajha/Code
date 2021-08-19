
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
    i64 n;cin >> n;
    multiset<i64> a;
    i64 cnt = 0;
    for(int k=0;k<n;++k){
        i64 temp; cin >> temp;
        if(temp == 1) {
            i64 x;cin >> x;
            a.insert(x - cnt);
        } else if(temp == 2){
            i64 x; cin >> x;
            cnt += x;
        } else {
            cout << (*a.begin()) + cnt << "\n";
            a.erase(a.begin());
        }
    }
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


