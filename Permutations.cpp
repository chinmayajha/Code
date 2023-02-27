#include "bits/stdc++.h"
using namespace std;
signed main() {
    int n, cnt = 1; cin >> n;
    if(n == 3 || n == 2) {
        cout << "NO SOLUTION";
        exit(0);
    }
    vector<int> a(n);
    for(int i = 1; i < n; i += 2) a[i] = cnt++;
    for(int i = 0; i < n; i += 2) a[i] = cnt++;
    for(auto& i : a) {cout << i << " ";} cout << "\n";
}
