#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for(int i = 0; i < n; ++i) cin >>a[i];
    for(int i = 0; i < n; ++i) if(a[i] >= a[i + 1]) {
        cout << a[i];
        return 0;
    } 
}
