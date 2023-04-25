#include "bits/stdc++.h"
using namespace std;
#define int long long

int find_root(int x) {
    int root = 1;
    while(root * root < x) ++root;
    return root;
}

signed main() {
    int n, m; cin >> n >> m;
    if(n >= m) cout << n << "\n";
    if(n * n < m) cout << "-1\n";
    else {
        int root = find_root(m);
        if(root * root == m) cout << m << "\n";
        else {
            int root1 = root, root2 = root;
            while(root1 * root2 < m) ++root2;
            
        }
    }
}
