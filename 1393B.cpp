
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
int n,k;
map<int,int> a;
int temp1,temp2;
void solve(){
    cin >> n;
    for(int i=0;i<n;++i) a[nxt()]++;
    cin >> k;
    string cur = "";
    for(auto i : a) temp1 += (i.second / 2), temp2 += (i.second / 4);
    for(int i=0;i<k;++i){
        char c;
        cin >> c;
        int x; cin >> x;
        temp1 -= (a[x]/2),temp2 -= (a[x]/4);
        if(c == '-') a[x]--;
        else a[x]++;
        temp1 += (a[x]/2);
        temp2 += (a[x]/4);
        if(temp1 >= 4 && temp2 >= 1) cur = "YES";
        else cur = "NO";
        cout << cur << "\n";
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


