
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
int n,m,x;
void solve(){
    cin >> n >> m;
    set<int> a;
    multiset<int> diff;
    a.insert(0);
    a.insert(n);
    diff.insert(n);
    for(int i=0;i<m;++i){
        cin >> x;
        auto q = a.upper_bound(x);
        auto p = q;
        --p;
        diff.erase(diff.find(*q-*p));
        diff.insert(*q-x);
        diff.insert(x-*p);
        a.insert(x);
        cout << *diff.rbegin() << " ";

    }

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


