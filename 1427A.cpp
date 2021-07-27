
#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    int n;cin >> n;
    vector<int> a(n);
    i64 sum = 0;
    for(int i=0;i<n;++i){cin >> a[i]; sum += a[i];}
    if(sum == 0){cout << "NO\n"; return;}
    
    cout << "YES\n";
    sort(all(a));
    vector<int> b = a;
    reverse(all(a));
    int temp = 0;
    for(auto& i : a){
        temp += i;
        if(temp == 0){
            for(auto& k : b) {cout << k << " ";} cout << "\n";
            return;
        }
    }
    for(auto& i : a) {cout << i << " ";} cout << "\n";
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
