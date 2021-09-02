
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
    vector<i64> a(7);
    inarr(a, 7);
    sort(all(a));
    for(i64 i = 0;i < 6; ++i) {
        for(i64 j = i+1;j < 6; ++j) {
            for(i64 k = j+1;k < 6; ++k) {
                if(a[i]+a[j]+a[k] == a[6]) {
                    cout << a[i] << " " << a[j] << " " << a[k];
                }
            }
        }
    }
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


