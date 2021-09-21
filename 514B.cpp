
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
int area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
}
void solve(){
	int n, p, q; cin >> n >> p >> q;
    set<pair<int, int>> b;
    for(int i = 0;i < n; ++i) {
        int x,y; cin >> x >> y;
        b.insert(make_pair(x, y));
    }
    vector<pair<int, pair<int, int>>> a;
    for(auto& i : b) a.emplace_back(make_pair(0, i));
    //
    n = sz(a);
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i].first == 1) continue;
        cnt++;
        for(int j = 0;j < n; ++j) {
            if(area(p, q, a[i].second.first, a[i].second.second, a[j].second.first, a[j].second.second) == 0) a[j].first = 1;
        }
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

