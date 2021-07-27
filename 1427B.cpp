
#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    int n,k;cin >> n >> k;
    int win = 0,losss = 0, wstreak = 0;
    vector<int>  loss;
    string s; cin >> s;
    for(int i=0;i<n;++i){
        if(s[i] == 'W'){
            win++;
            wstreak += (i == 0 || s[i-1]=='L'); 
        } else {
            losss++;
            if(i == 0 || s[i-1] == 'W') loss.emplace_back(0);
            loss[sz(loss)-1]++;
        }
    }
    if(k >= losss){cout << 2*n - 1 << "\n"; return;}
    if(win == 0){
        cout << max(0,2*k-1) << "\n"; 
        return;
    }
    if(s[0] == 'L')loss[0] = INT_MAX;
    if(s[n-1] == 'L')loss[sz(loss)-1] = INT_MAX;
    sort(all(loss));
    win += k;
    for(auto& i : loss){
        if(k - i < 0)break;
        k -= i;
        wstreak--;
    }
    cout << 2*win - wstreak << "\n";
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
