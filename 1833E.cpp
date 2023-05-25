#include "bits/stdc++.h"
using namespace std;
#define int long long

int t, n, loops, lines;
vector<set<int>> a;
vector<int> vis;

void dfs(int node, int parent) {
    vis[node] = 1;
    for(auto& i : a[node]) {
        if(i != parent && vis[i]) {
            // Loop found!
            loops += 1;
            return;
        } else if(i != parent && !vis[i]) dfs(i, node);
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        a.assign(n, set<int>());
        vis.assign(n, 0);
        lines = 0, loops = 0;
        for (int i = 0, x; i < n; ++i) {
            cin >> x; --x;
            a[i].insert(x);
            a[x].insert(i);
        }
        
        // Input is a forest of loops and lines
        // Ans is min = (lines >= 1) + loops, max = lines + loops
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                dfs(i, -1);
                lines += 1;
            }
        }
        loops /= 2;
        lines -= loops; // All loops will be counted as lines as well
        cout << (lines >= 1) + loops << " " << lines + loops << "\n";
    }
}
