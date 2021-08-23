
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
string gen(int n)
{
    string s(n,'0');
    for(auto& i : s) i = (rand()%2 ? '1' : '0');
    return s;
}
string solve(){
    int n; cin >> n;
    set<string> a;
    for(int i=0;i<n;++i) {
        string s; cin >> s;
        a.insert(s);
    }
    while(true) {
        string s = gen(n);
        if(a.find(s) == a.end()) return s;
    }
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        cout << solve() << "\n";
    }
}


