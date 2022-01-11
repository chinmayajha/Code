#include "bits/stdc++.h"
using namespace std;

signed main() {
    int n, k; cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0, x; i < k - 1; ++i) {
        cin >> x;
        pq.push(x);
    }
    for(int i = k - 1, x; i < n; ++i) {
        cin >> x;
        pq.push(x);
        if((int)pq.size() > k) pq.pop();
        cout << pq.top() << "\n";
    }
}
