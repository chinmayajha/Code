
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
void solve3(){
    vector<int> a(6),b(6),c(6);
    inarr(a, 6); inarr(b, 6); inarr(c, 6);
    sort(all(a)); sort(all(b)); sort(all(c));
    for(int i = 1;i <= 99; ++i) {
        if(i <= 9) {
            if(!binary_search(all(a), i) && !binary_search(all(b), i) && !binary_search(all(c), i)) {
                cout << i-1;
                return;
            }
        } else {
            if((binary_search(all(a), i/10) && binary_search(all(b), i%10))
            || (binary_search(all(b), i/10) && binary_search(all(a), i%10))
            || (binary_search(all(b), i/10) && binary_search(all(c), i%10))
            || (binary_search(all(c), i/10) && binary_search(all(b), i%10))
            || (binary_search(all(c), i/10) && binary_search(all(a), i%10))
            || (binary_search(all(a), i/10) && binary_search(all(c), i%10))) continue;
            cout << i - 1;
            return;
        }
    }

}
void solve2(){
    vector<int> a(6),b(6);
    inarr(a, 6); inarr(b, 6);
    sort(all(a)); sort(all(b));
    for(int i = 1;i < 100; ++i) {
        if(i <= 9) {
            if(!binary_search(all(a), i) && !binary_search(all(b), i)) {
                cout << i-1;
                return;
            }
        } else {
            if((binary_search(all(a), i/10) && binary_search(all(b), i%10))
            || (binary_search(all(b), i/10) && binary_search(all(a), i%10))) continue;
            cout << i - 1;
            return;
        }
    }

}
void solve1(){
    vector<int> a(6);
    inarr(a, 6);
    sort(all(a));
    for(int i = 1;i < 100; ++i) {
        if(!binary_search(all(a), i)) {
            cout << i-1;
            return;
        }
    }
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int n = nxt();
    if(n == 1) solve1();
    else if(n == 2) solve2();
    else solve3();
}

