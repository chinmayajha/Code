
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
const int N = 1e6 + 10;
int a[N], n, q, A, B, l, r;
vector<int> b[N];

void solve() {
    set<int> st;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        st.insert(a[i]);
    }
    for(int i = 0; i < n; ++i) b[a[i]].push_back(i + 1);
    while(q--) {
        cin >> l >> r;
        //
        int chk = 1;
        for(auto& i : st) {

            int left = lower_bound(all(b[i]), l) - b[i].begin();
            int right = upper_bound(all(b[i]), r) - b[i].begin();
            int diff = right - left;

            if(diff >= A && diff <= B) {
                cout << i << "\n";
                chk = 0;
                break;
            }
        }
        if(chk) cout << "-1\n";
    }
}

void solve12() {
    for(int i = 0; i < n; ++i) cin >> a[i];
    while(q--) {
        cin >> l >> r; l--; r--;
        map<int, int> x;
        for(int i = l; i <= r; ++i) x[a[i]]++;
        bool chk = 1;
        for(auto& i : x) {
            if(i.second >= A && i.second <= B) {
                cout << i.first << "\n";
                chk = 0;
                break;
            }
        }
        if(chk) cout << "-1\n";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int s; cin >> s;
    cin >> n >> q >> A >> B;
    if(s == 1 || s == 2) solve12();
    else solve();
}
