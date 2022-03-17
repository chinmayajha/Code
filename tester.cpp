#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    vector<int> s;
    set<int> a{1, 2, 3, 4};
    copy(s.begin(), s.end(), a.begin());
    for(auto& i : a) {cout << i << " ";} cout << "\n";
}