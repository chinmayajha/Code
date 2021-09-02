
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
    int n, odd = 0, even = 0, cnt = 0, cnt2 = 0;
    cin >> n;
    vector<int> a(n);
    for(auto& i : a) {
        i = nxt() % 2;
        odd += i;
        even += (i == 0);
    }
    if(abs(odd - even) > 1) {
        return -1;
    }
    if(odd > even) {
        int cur = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] == 1) {
                cnt += abs(cur - i);
                cur += 2;
            }
        }
        return cnt;
    } else if(even > odd) {
        int cur = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] == 0) {
                cnt += abs(cur - i);
                cur += 2;
            }
        }
        return cnt;
    } else {
        int cur = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] == 1) {
                cnt += abs(cur - i);
                cur += 2;
            }
        }
        cur = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] == 0) {
                cnt2 += abs(cur - i);
                cur += 2;
            }
        }
        return min(cnt, cnt2);
    }
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        cout << solve() << "\n";
    }
}

