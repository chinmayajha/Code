
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define print(...)
#define dbg(...)
#endif

pair<int, int> findBreakpoint(vector<int> a) {
    int n = sz(a);    
    for(int i = 0; i < n; ++i) {
        if(a[i] != a[n - 1 - i]) return make_pair(i, n - 1 - i);
    }
    return make_pair(-1, -1);
}

string solve(){
    int n; cin >> n;
    vector<int> a(n), b, c;
    for(int i = 0; i < n; ++i) cin >> a[i];
    if(n <= 2) return "YES";
    
    pair<int, int> check = findBreakpoint(a);
    if(check.first == -1) return "YES";

    for(auto& i : a) if(i != a[check.first]) b.push_back(i);
    for(auto& i : a) if(i != a[check.second]) c.push_back(i);
    
    check = findBreakpoint(b);
    if(check.first == -1) return "YES";
    check = findBreakpoint(c);
    if(check.first == -1) return "YES";

    return "NO";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        cout << solve() << "\n";
    }
}
