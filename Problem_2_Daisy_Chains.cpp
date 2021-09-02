
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
vector<vector<i64>> b;
void func(vector<i64> arr, i64 start, i64 end){
    if (end == arr.size()) return;
    else if (start > end) func(arr, 0, end + 1);
    else {
        vector<i64> x;
        for (i64 i = start; i <= end; i++) {
            x.push_back(arr[i]);
        }
        b.emplace_back(x);
        x.clear();
        func(arr, start + 1, end);
    }
    return;
}
void solve(){
    i64 n;
    cin >> n;
    vector<i64> a(n);
    int cnt = 0;
    generate_n(a.begin(), n, nxt);
    func(a, 0, 0);
    for(i64 i = 0;i < sz(b); ++i) {
        i64 temp = accumulate(all(b[i]), 0ll);
        for(int j = 0; j < sz(b[i]); ++j) {
            if(b[i][j] * sz(b[i]) == temp) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
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


