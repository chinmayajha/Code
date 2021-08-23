
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i=0;i<n;++i) mp[nxt()]++;
    if(n <= 2) {
        cout << "0\n";
        return;
    }
    int mx = INT_MIN;
    for(auto& i : mp) mx = max(mx, i.second);
    cout << n - mx - (mx == 1) << "\n";

}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        solve();
    }
}


