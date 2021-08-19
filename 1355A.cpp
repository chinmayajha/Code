
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 Digits(i64 n){
    int largest = 0,smallest = 9;
    while (n) {
        int r = n%10;
        largest = max(r, largest),smallest = min(r, smallest);
        n/=10;
    }
    return largest*1ll*smallest;
}
void solve(){
    i64 n,k; cin >>  n >> k;k--;
    while(k>0 && n%10 != 0){
        k--;
        i64 x = Digits(n);
        if(!x)break;
        n += x;
    }
    cout << n << "\n";
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}


