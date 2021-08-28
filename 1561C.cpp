
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//

struct e {
    i64 k, power = 0;
    vector<i64> a;
};
bool cmp(const e &x, const e &y){
    return x.power < y.power;
}
i64 n, k, temp, ans, cnt;
void solve(){
    set<pair<i64, i64>> s;
    ans = 0, cnt = 0;
    cin >> n;
    vector<e> b(n);
    for (i64 i = 0; i < n; i++) {
        cin >> k;
        for (i64 j = 0; j < k; j++) {
            temp = nxt() - j;
            b[i].a.emplace_back(temp);
            b[i].power = max(b[i].power, temp);
        }
        s.insert(make_pair(b[i].power, i));
    }
    
    while (sz(s) > 0) {
        i64 index = (*s.begin()).second;
        s.erase(s.begin());
        ans = max(ans, b[index].power -cnt + 1);
        cnt += sz(b[index].a);
    }
    cout << ans << '\n';
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


