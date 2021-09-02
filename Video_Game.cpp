
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
    int n, h, cur = 0, hand = 0;
    cin >> n >> h;
    vector<int> a(n);
    generate_n(a.begin(), n, nxt);
    int k = 0;
    while(1) {
        k = nxt();
        if(k == 0) break;
        //
        if(k == 1) cur = max(0, cur - 1);
        if(k == 2) cur = min(n - 1, cur + 1);
        if(k == 3) {
            if(a[cur] <= 0) continue;
            if(hand == 0) a[cur]--;
            hand = 1;
        }
        if(k == 4) {
            if(a[cur] >= h) continue;
            if(hand > 0) a[cur]++;
            hand = 0;
        }
    }
   
    for(auto& i : a) {cout << i << " ";} cout << "\n";

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


