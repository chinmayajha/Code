#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;
    vector<pair<string, int>> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    for(int i = 0; i < n; ++i) 
        for(int j = i + 1; j < n; ++j) 
            cnt += (a[i].second < a[j].second && a[i].first != a[j].first);
    cout << cnt;
}