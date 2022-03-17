#include "bits/stdc++.h"
using namespace std;
#define int long long

int n;
vector<pair<int, int>> a;

void preprocess() {
    bool check1 = all_of(a.begin(), a.end(), [&](pair<int, int>& pp){return (pp.second == 0);});
    if(check1) {
        // SUBTASK 4 DONE
        int ans = 0;
        sort(a.begin(), a.end(), [&](pair<int, int>& p1, pair<int, int>& p2){return p1.first < p2.first;});
        for(int i = 0; i < n; ++i) {
            ans = max(ans, (n - i) * a[i].first);
        }
        cout << ans;
    }
    bool check2 = all_of(a.begin(), a.end(), [&](pair<int, int>& pp){return (pp.first == pp.second);});
    if(check2) {
        // SUBTASK 5
        sort(a.begin(), a.end(), [&](pair<int, int>& p1, pair<int, int>& p2){return p1.first < p2.first;});
        int ans = n * a[0].first;
        auto b = a;
        for(int i = 1; i < n; ++i) {
            b[i].second += a[i].second;
            ans = max(ans, (n - i) * a[i].first + b[i - 1].second);
        }
        cout << ans;
    }
}

signed main() {
    cin >> n;
    a.resize(n); for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    preprocess();
}