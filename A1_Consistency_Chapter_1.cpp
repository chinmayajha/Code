
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
string s;
bool isvowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
void solve(){
    cin >> s;
    int cnt = INT_MAX;
    for(char k = 'A'; k <= 'Z'; ++k) {
        int cur = 0;
        for(auto& i : s) {
            if(i == k) continue;
            if(isvowel(i) && isvowel(k)) cur += 2;
            else if(!isvowel(i) && !isvowel(k)) cur += 2;
            else cur += 1;
        }
        cnt = min(cur, cnt);
    }
    
    cout << cnt << "\n";
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}


