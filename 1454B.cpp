
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
int solve(){
    int n;cin >> n;
    vector<int> a(n);
    generate_n(a.begin(), n, nxt);
    map<int,int> x;
    for(auto& i : a)x[i]++;
    for(auto& i : x){
        if(i.second>1)continue;
        for(int k=0;k<n;++k){
            if(a[k] == i.first) return k+1;
        }
    }
    return -1;
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        cout << solve() << "\n";
    }
}
