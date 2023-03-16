#include "bits/stdc++.h"
using namespace std;
#define int long long

int mexx(vector<int> &arr, int N) {
  sort(arr.begin(), arr.end());
  int mex = 0;
  for (int idx = 0; idx < N; idx++) {
    if (arr[idx] == mex) mex += 1;
  }
  return mex;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, k, mex = -1; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    mex = mexx(a, n);
    
    cout << min(k, mex);
}
