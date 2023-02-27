#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a, b, ans;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            if(x % 2) a.push_back(x);
            else b.push_back(x);
        }
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        // print 2 Es and 1 O
        if(a.size() < b.size()) swap(a, b);
        if((int) a.size() - (int) b.size() > 1) cout << "-1\n";
        else {
            while(true) {
                if(a.size() > 0) {
                    ans.push_back(a.back());
                    a.pop_back();
                } else break;

                if(a.size() > 0) {
                    ans.push_back(a.back());
                    a.pop_back();
                } else break;

                if(b.size() > 0) {
                    ans.push_back(b.back());
                    b.pop_back();
                } else break;

                if(b.size() > 0) {
                    ans.push_back(b.back());
                    b.pop_back();
                } else break;
            }
            for(auto& i : ans) {cout << i << " ";} cout << "\n";
        }
    }
}


/* 
e o o e o o e o
o e e o e e o e
 
    1 2 3 4 5 6 7 8 9 10
e = 0 1 2 2 3 4 4 5 6 6 
o = 1 1 1 2 2 2 3 3 3 
o 
o e
o e e
o e e o 
o e e o e
o e e o e e
o e e o e e o
o e e o e e o e
o e e o e e o e e
*/