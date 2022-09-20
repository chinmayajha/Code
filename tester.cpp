#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int q; cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq, pq2, empty;
    pq.push(0);
    while(q--) {
        int temp, x; cin >> temp;
        if(temp == 3) {
            cout << pq.top() << "\n";
        } else if(temp == 2) {
            cin >> x;
            while((int) pq.size() > 0) {
                pq2.push(pq.top() ^ x);
                pq.pop();
            }
            pq = pq2;
            pq2 = empty;
        } else if(temp == 1) {
            cin >> x;
            pq.push(x);
        }
    }
}