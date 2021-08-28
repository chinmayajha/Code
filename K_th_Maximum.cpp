
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
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n);
    generate_n(a.begin(), n, nxt);
    i64 x = *max_element(all(a));
    vector<int> b;
    for(i64 i = 0;i < n; ++i) if(a[i] == x) {
        b.emplace_back(i+1);
    }
    i64 sum = 0;
    for(auto& ind : b) if(ind >= k) sum +=  1 + n - ind;
    cout << sum << "\n";
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

