#include "bits/stdc++.h"
using namespace std;
#define int long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
// #include "debug.hpp"
template <typename T>
bool contains(const std::multiset<T>& v, const T& elem) {
    return std::find(v.begin(), v.end(), elem) != v.end();
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        multiset<int> s;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            s.insert(x);
        }
        bool chk = 0;
        multiset<int> tt = s;
        for(auto i : s) {
            tt.erase(tt.find(i));
            while(i > n || contains(tt, i)) i /= 2;
            tt.insert(i);
            if(i == 0) {
                cout << "NO\n";
                chk = 1;
                break;
            }
        }
        if(!chk)  cout << "YES\n";
    }
}
