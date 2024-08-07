
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
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    generate_n(a.begin(), n, nxt);
    int cur = a.back();
    for(int i = n - 2; i > 0; --i) {
        if(a[i] > cur) {
            cnt++;
            cur = a[i];
        }
    }
    if(a[0] >= cur) {
        a[0] = cur;
        cnt++;
    }
    cout << (cur == a[0] ? cnt : -1) << "\n";
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

