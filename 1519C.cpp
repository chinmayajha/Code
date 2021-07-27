#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define rall(x) (x).rbegin(), (x).rend()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    int n;cin >> n;
    vector<int> a(n),b(n);inarr(a,n);inarr(b,n);
    vector<vector<i64>> x(n);
    for(int i=0;i<n;++i) x[a[i]-1].emplace_back(b[i]);
    for(auto& i : x){
        sort(rall(i));
        for(int j=sz(i)-2;j>=0;--j) i[j] += i[j+1];
        i.emplace_back(0);
    }
    for(int k = 1; k <= n; ++k){
        i64 sum = 0;
        for(auto& i : x){
            int ind = ((sz(i) - 1)/k)*k;
            sum = sum + i[0] - i[ind];
        }
        cout << sum <<  " ";
    }
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
 