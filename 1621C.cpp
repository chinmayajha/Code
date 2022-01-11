#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int t = 1;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n, -1);
        for(int i = 0, x, y; i < n; ++i) {
            if(a[i] == -1) {
                vector<int> cycle;
                cout << "? " << i + 1 << endl;
                cin >> y;
                cout << "? " << i + 1 << endl;
                cin >> x;
                cycle.push_back(x - 1);
                while(y != x) {
                    cout << "? " << i + 1 << endl;
                    cin >> x;
                    cycle.push_back(x - 1);
                }
                for(int j = 0; j < (int)cycle.size(); ++j) {
                    a[cycle[j]] = cycle[(j + 1) % (int)cycle.size()];
                }
            }
        }
        cout << "! ";
        for(int i = 0; i < n; ++i) cout << a[i] + 1 << " ";
        cout << endl;
    }
}
