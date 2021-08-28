
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 a, b;
void solve(){
    cin >> a >> b;
    i64 k = (a + b + ((a+b)%2))/2;
    i64 mn = (a < k ? b - k : a - k);
    i64 mx = min(a, k) + min(b, k);

    int temp = ((a+b)%2 ? 1 : 2);
    int cnt = 0;
    for(i64 i = mn;i < mx + 1; i += temp) cnt++;
    cout << cnt << "\n";
    for(i64 i = mn;i < mx + 1; i += temp) cout << i << " ";
    cout << "\n";
    
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
