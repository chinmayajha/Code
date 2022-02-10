#include "bits/stdc++.h"
using namespace std;
#define int long long



signed main() {
    multiset<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(2);
    for(auto& i : s) cout << i << " ";
    cout << endl;
    s.erase(s.begin());
    for(auto& i : s) cout << i << " ";
}