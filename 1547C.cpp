
#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
#ifndef ONLINE_JUDGE
    #define db(x) cerr << #x <<" = " << x << "\n";
#else
    #define db(...)
#endif
//
void solve(){
    int k,n,m;cin >> k >> n >> m;
    vector<int> a(n),b(m);
    inarr(a,n);inarr(b,m);
    int i = 0, j = 0;
    vector<int> ans;
    while(i<n || j<m){
        if(i<n && a[i] == 0){
            k++;
            ans.emplace_back(a[i]);
            i++;
        } else if(j<m && b[j]==0){
            k++;
            ans.emplace_back(b[j]);
            j++;
        }
        else if(i<n && a[i]<=k){
            ans.emplace_back(a[i]);
            i++;
        } else if(j<m && b[j]<=k){
            ans.emplace_back(b[j]);
            j++;
        } else {
            cout << "-1\n";
            return;
        }
    }
    for(auto& w : ans)cout << w << " ";
    cout << "\n";
    
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
