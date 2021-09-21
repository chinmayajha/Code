
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
vector<int> a;
string solve(){
    for(int i = 1;i <= 11111; ++i) a.emplace_back(i*i);
    int x, y; cin >> x >> y;
    if(x == 0 || y == 0) return "black";
    string ans;
    int sqr = x*x + y*y;
    if(binary_search(all(a), sqr)) return "black";
    int index = lower_bound(all(a), sqr) - a.begin();
    if(index % 2 == 0) ans = "black";
    else ans = "white";
    if(x*y < 0) ans = (ans == "white" ? "black" : "white");
    return ans;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        cout << solve();
    }
}

