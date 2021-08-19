
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
    int n;
    cin >> n;
    string s; cin >> s;
    if(s[0] == '?'){
        if(n == 1){
            if(s == "?") cout << "B";
            else cout << s;
        } else {
            string temp('?',n);
            if(s == temp){
                temp = string('B',n);
                for(int i=0;i<n;i+=2) temp[i] = 'R';
                cout << temp; return;
            }
        }
    }
    for(int i=1;i<n;++i){
        if(s[i] != '?') continue;
        if(s[i-1] == 'B') s[i] = 'R';
        else s[i] = 'B';
    }
    cout << s;
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve(); cout << "\n";
    }
}


