
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define print(...)
#define dbg(...)
#endif
int64_t st, n, m, temp, l, r, v, a[int64_t(2e5 + 10)];

int64_t calculate_inversions(int64_t x, int64_t y) {
    int64_t cnt = 0;
    for(int64_t i = x - 1; i < y; ++i) for(int64_t j = i + 1; j < y; ++j) cnt += (a[i] > a[j]);
    return cnt;
}

void solve1237(){ // brute force
    for(int64_t i = 0; i < m; ++i) {
        cin >> temp;
        if(temp == 1) {
            cin >> l >> r >> v;
            for(int64_t j = l - 1; j < r; ++j) a[j] = v;
        } else {
            cin >> l >> r;
            cout << calculate_inversions(l, r) << "\n";
        }
    }
}

map<pair<int64_t, int64_t>, int64_t> mp;
void solve56(){ // no updates, only queries 
    for(int64_t i = 0; i < m; ++i) {
        cin >> temp >> l >> r;
        int64_t q = mp[{l, r}];
        if(q == 0) q = calculate_inversions(l, r) + 1;
        mp[{l, r}] = q;
        cout << q - 1 << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
cerr << 10000;
    cin >> st >> n >> m;
    for(int i = 0; i < n; ++i) cin >> a[i];
    //
    if(st == 4) return 0; //no queries
    else if(st == 1 || st == 2 || st == 3 || st == 7) solve1237();
    else if(st == 5 || st == 6) solve56(); 
}
