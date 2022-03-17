#include "bits/stdc++.h"
using namespace std;

signed main() {
    int n; string s; deque<int> d;
    cin >> n; cin >> s;
    d.push_back(n);
    for(int i = n - 1; i >= 0; --i) {
        if(s[i] == 'R') d.push_front(i);
        else d.push_back(i);
    }
    while((int) d.size() > 0) {
        cout << d.front() << " ";
        d.pop_front();
    }
}
