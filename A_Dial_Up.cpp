
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
int findfromleft(vector<int> a, int x) {
    for(int i=0;i<sz(a); ++i) if(a[i] == x) return i;
    return -1;
}
int findfromright(vector<int> a, int x) {
    for(int i=sz(a)-1;i>=0; --i) if(a[i] == x) return i;
    return -1;
}
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n), t(m), b;
    generate_n(a.begin(), n, nxt);
    generate_n(t.begin(), m, nxt);
    int cur = 0, cnt = 0;
    while(b != t) {
        if(a[0] == t[cur]) {
            b.emplace_back(a[0]);
            cur++; 
            continue;
        }
        int l = findfromleft(a, t[cur]);
        if(l == -1) {
            cout << -1;
            exit(0);
        }
        r = findfromright(a, t[cur]);
        
    }

}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}


