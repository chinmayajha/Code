
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 checkbig(vector<i64> &a, int x) {
    int cnt = 0;
    for(auto& i : a) cnt += (x <= i);
    return cnt;
}
void solve(){
    i64 n;
    cin >> n;
    vector<i64> a(n), b(n);
    generate_n(a.begin(), n, nxt);
    generate_n(b.begin(), n, nxt);
    sort(all(a));
    i64 cnt = 1;
    for(i64 i = n - 1; i >= 0; --i) {
        cnt *= (checkbig(b, a[i]) - (n - i - 1));
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


