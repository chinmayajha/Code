
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
set<int>  factorize(int k) {
    set<int> a;
    for(int i = 1; i*i <= k + 1; ++i) {
        if(k % i == 0) {
            a.insert(i);
            a.insert(k / i);
        }
    }
    return a;
}
int solve(){
    int n, k;
    cin >> n >> k;
    if(k >= n) return 1;
    set<int> a = factorize(n);
    int mx = n;
    for(auto& i : a) if(i <= k) mx = n / i;
    return mx;
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        cout << solve() << "\n";
    }
}


