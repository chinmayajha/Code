
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
#ifndef ONLINE_JUDGE
    #include "debug.hpp"
#else
    #define print(...)
    #define debug(...)
#endif
int arr[1000000];
int solve(){
    int a,b; cin >> a >> b;
    int cnt = a;
    if(a == 1 && b == 0) return 1;
    if(a == 1 && b == 1) return 3;
    if(arr[a - 1] == b) return cnt;
    // not in range ^ so
    cnt++;
    if((arr[a - 1] ^ b) != a) return cnt;
    else return cnt + 1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    cin >> testt;
    for(int i = 1; i < 1000000; ++i) arr[i] = arr[i - 1] ^ i;
    for(int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        cout << solve() << "\n";
    }
}