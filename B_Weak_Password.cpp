
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
    string s;cin>>s;
    if(s[0]==s[1] && s[1]==s[2] && s[2]==s[3]){
        cout << "Weak";
    } else if(s[1]-'0' == ((s[0]-'0')+1)%10 && s[2]-'0' == ((s[1]-'0')+1)%10 && s[3]-'0' == ((s[2]-'0')+1)%10) cout << "Weak";
    else {
        cout << "Strong";
    }
    
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


