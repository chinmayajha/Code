
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
// bool cmp(pair<int,int>& a, pair<int,int>& b) {
//     return a.first > b.first;
// }
bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}
 
void solve(){
    int n, q, k, pos;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0;i < n; ++i) {
        cin >> a[i].second;
        a[i].first = i+1;
    }
    sort(all(a), cmp);
    cin >> q;
    while(q--) {
        cin >> k >> pos;
        vector<pair<int, int>> b(a.begin(), a.begin() + k);
        sort(all(b));
        cout << b[pos - 1].second << "\n";
    }
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}


