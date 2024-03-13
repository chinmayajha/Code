#include "bits/stdc++.h"
using namespace std;
#define int long long

vector<int> prefMex(vector<int>& A, int n) {
    vector<bool> b(n + 1, 0);
    int mex = 0;
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        b[A[i]] = 1;
        while (b[mex] == 1) mex++;
        result[i] = mex;
    }
    
    return result;
}

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int> mex1 = prefMex(a, n);
        reverse(a.begin(), a.end());
        vector<int> mex2 = prefMex(a, n);
        reverse(mex2.begin(), mex2.end());

        int bp = -1; // breaking point
        for(int i = 0; i < n - 1; ++i) {
            if(mex1[i] == mex2[i + 1]) {
                bp = i + 1;
                break;
            }
        }
        
        if(bp == -1) {
            cout << "-1\n";
        } else {
            cout << "2\n";
            cout << "1 " << bp << "\n";
            assert(bp + 1 <= n);
            cout << bp + 1 << " " << n << "\n";
        }
    }
}

