#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    int n, q, typ, x, y; cin >> n >> q;
    map<int, multiset<int>> a; // box : cards
    map<int, set<int>> b; // card : boxes
    while(q--) {
        cin >> typ;
        if(typ == 1) {
            cin >> x >> y; // y is box, x is card
            a[y].insert(x); // card x into box y
            b[x].insert(y); // box y into card x
        } else if(typ == 2) {
            cin >> x;
            for(auto& i : a[x]) cout << i << " ";
            cout << "\n";
        } else if(typ == 3){
            cin >> x;
            for(auto& i : b[x]) cout << i << " ";
            cout << "\n";
        }
    }
}
