
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
vector<int> a{1,2,6,24,120,720,5040,40320,362880,3628800};
int check(int num){
    int i=0;
    while(i < sz(a) && a[i] <= num) i++;
    return i-1;
}
void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    while(n > 0){
        int x = a[check(n)];
        cnt += (n/x);
        n -= ((n/x)*x);
    }
    cout << cnt;
    // generate_n(a.begin(), n, nxt);
    
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


