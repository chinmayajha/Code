
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
    int n, even = 0, odd = 0; cin >> n;
    while(n--) {
        int k = nxt();
        even += (k % 2 == 0);
        odd += (k % 2);
    }
    if(even - odd == 1 || even - odd == 0) {
        cout << even + odd;
    } else if (even > odd) {
        cout << 2*odd + 1;
    } else {
        //odd > even
        int k = 2 * even;
        odd -= even;
        while(odd > 1) {
            odd -= 2;
            k++;
            if(odd > 0) {
                odd -= 1;
                k++;
            }
        }
        if(odd == 1) k--;
        cout << k;
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


