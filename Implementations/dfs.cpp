#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, p, q;
bool adj[1001][1001];
bool vis[1001];

void DFS(int v) {
    int j;
    vis[v] = 1;
    cout << v << "\n";
    for (j = 1; j <= n; ++j) {
        if (vis[j] == 0 && adj[v][j]) {
            DFS(j);
        }
    }
}
int main() {
    //
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> p >> q;
        adj[p][q] = 1;
        adj[q][p] = 1;
    }
    DFS(1);
}