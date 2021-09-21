
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
#ifndef ONLINE_JUDGE
    #include "debug.hpp"
#else
    #define print(...)
    #define debug(...)
#endif
void solve(){
	int n; cin >> n;
    vector<int> a(n), b(n);
    priority_queue<int> pq;
    inarr(a, n);
    inarr(b, n);
    for(int i = 0;i < n; ++i) if(!b[i]) pq.push(a[i]);
    for(int i = 0;i < n; ++i) if(!b[i]) {
        a[i] = pq.top();
        pq.pop();
    }
    for(auto& i : a) {cout << i << " ";} cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
