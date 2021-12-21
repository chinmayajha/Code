
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

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int mx = *max_element(all(a));
    if(n == 1) {
        cout << a[0] << "\n";
        return;
    }
    if(mx != a[0] && mx != a[n -1]){
        cout << "-1\n";
        return;
    }
    deque<int> b;
    int i = 0, j = n - 1;
    while(i <= j) {
        if(a[i] > a[j]) {
            b.push_front(a[i]);
            i++;
        } else {
            b.push_back(a[j]);
            j--;
        }
    }
    for(auto& k : b) cout << k << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
