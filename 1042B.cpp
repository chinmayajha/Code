
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
int n, cost = 1e9;
vector<pair<int, string>> a(10000);
int getcost(string p, string q) {
    int cost1 = 1e7, cost2 = 1e7;
    for(auto& i : a) {
        if(i.second == p) cost1 = min(cost1, i.first);
        else if(i.second == q) cost2 = min(cost2, i.first);
    }
    return cost1 + cost2;
}
void solve(){
	cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    int cost1 = 1e7, cost2 = 1e7, cost3 = 1e7;
    for(auto& i : a) {
        if(sz(i.second) == 3) cost = min(cost, i.first);
        else if(sz(i.second) == 2) continue;
        if(i.second[0] == 'A') cost1 = min(cost1, i.first);
        if(i.second[0] == 'B') cost2 = min(cost2, i.first);
        if(i.second[0] == 'C') cost3 = min(cost3, i.first);
    }
    if(cost1 != 1e7 && cost2 != 1e8 && cost3 != 1e7) cost = min(cost, cost1 + cost2 + cost3);
    //
    cost = min(cost, getcost("AB", "C"));
    cost = min(cost, getcost("A", "BC"));
    cost = min(cost, getcost("AC", "B"));
    cost = min(cost, getcost("AB", "BC"));
    cost = min(cost, getcost("AC", "BC"));
    cost = min(cost, getcost("AC", "AB"));
    if(cost == 1e9) cout << -1;
    else cout << cost;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

