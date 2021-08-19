
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
string nxt(){string x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    int n;
    cin >> n;
    vector<string> a(n);
    inarr(a,n);
    int m = sz(a[0]);
    string s = "";
    for(int i=0;i<m;++i){
        set<char> x;
        for(int j=0;j<n;++j) x.insert(a[j][i]);
        if(sz(x) >= 3) s += "?";
        else if(x.count('?') > 0 && sz(x) == 2) {
            x.erase('?');
            s += (*x.begin());
        } else if(sz(x) == 2) s += '?';
        else {
            if(*x.begin() == '?') s += 'a';
            else s += *x.begin();
        }
    }
    cout << s;
    
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}


