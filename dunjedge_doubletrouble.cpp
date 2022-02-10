#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, k, x;
multiset<int> s;

signed main() {
    // damn gives 56 points
    cin >> n >> k;
    while(n--) {
        cin >> x;
        s.insert(x);
    }
    
    while(k--) {
        x = *(s.begin());
        s.erase(s.lower_bound(x));
        s.insert(x * 2);
    }
    cout << *(s.rbegin());
}