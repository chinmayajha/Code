
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
    int n,k;
    cin >> n >> k;
    string s(n,'a');
    /*
        You need to notice that, if first B is at index i, then there are n - i - 1 strings possible in that case.
        SO for each possible value of i (from end), we check if k is ever less than or equal to (n - i - 1). If not
        then we decrement k by (n - i - 1) as these (n - i - 1) strings are of no use to us (i.e. remove all strings which have the leftmost 'b' at the current position)
        IF k <= (n - 1 - i), then it is known that the current index (i) is correct, and then the second B is placed at the (n - k)th index.
        Therefore the first B is placed at an i, where k <= (n - i - 1) and the second B is placed at (n - k), when the first B is placed at i.
    */
    for(int i = n - 2; i >= 0; --i){
        if(k <= (n - 1 - i)) {
            s[i] = 'b';
            s[n - k] = 'b';
            cout << s << "\n";
            return;
        }
        k -= (n - i - 1);
    }
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


