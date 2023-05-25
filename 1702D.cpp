#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        string s; cin >> s; int n = s.size();
        int p; cin >> p;
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; ++i) a[i].first = s[i] - 'a' + 1, a[i].second = i;
        sort(a.begin(), a.end());
        int index = 0;
        while(p - a[index].first >= 0) {
            p -= a[index].first;
            index++;
        }
        index--;
        if(index == -1) cout << "\n";
        else {
            sort(a.begin(), a.begin() + index, [](pair<int, int> xx, pair<int, int> yy){ return xx.second < yy.second;});
            for(int i = 0; i <= index; ++i) cout << (char) (a[i].first + 96);
            cout << "\n";
        }
    }
}
