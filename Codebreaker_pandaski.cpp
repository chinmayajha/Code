// https://codebreaker.xyz/problem/pandaski
// https://codeforces.com/group/fXPc2tNEPp/contest/362551/problem/B
#include "bits/stdc++.h"
using namespace std;
#define int long long

struct element {
    int x, y, m, e;
};
bool cmp(element& p, element& q) {
    return p.y > q.y;
}

int n, h;
vector<element> a;
vector<int> dp(2002, 0);

signed main() {
    cin >> n >> h;
    a.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y >> a[i].m >> a[i].e;
    
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(abs(a[j].y - a[i].y) > a[j].e || abs(a[j].x - a[i].x) > a[j].e) continue;
            dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += a[i].m;
    }
    cout << *max_element(dp.begin(), dp.end());
}