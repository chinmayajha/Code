#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, count = 0; cin >> n;
        multiset<int> b;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            b.insert(x);
        }

        while(true) {
            if(b.size() == 0) break;
            int first = *b.begin();
            b.erase(b.find(first));

            first += 1;
            while(b.size() > 0) {
                if(b.count(first)) {
                    b.erase(b.find(first));
                    first += 1;
                } else break;
            }
            count += 1;
        }

        cout << count << "\n";
            
    }
}

/*

1 1 4 4 2 3 2 3
1 1 2 2 3 3 4 4

1 2 3 4
1 2 3 4

*/