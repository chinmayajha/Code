#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e9;

vector<int> adj[MAXN];
int dist[MAXN], vis[MAXN];

int main() {
    int tt; cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        int k = ceil(sqrt(n));
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        fill(dist, dist+n+1, INF);
        for (int s = 1; s <= n; s++) {
            if (!vis[s]) {
                queue<int> q;
                q.push(s);
                dist[s] = 0;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    if (vis[u]) continue;
                    vis[u] = true;
                    for (int v : adj[u]) {
                        if (dist[v] > dist[u]+1) {
                            dist[v] = dist[u]+1;
                            q.push(v);
                        }
                    }
                }
            }
        }
        int cnt = 0;
        vector<int> S;
        for (int i = 1; i <= n; i++) {
            if (dist[i] <= k) {
                S.push_back(i);
                cnt++;
            }
        }
        if (cnt > k) {
            cout << "-1\n";
            continue;
        }
        cout << S[0];
        for (int i = 1; i < (int) S.size(); i++) {
            cout << " " << S[i];
        }
        cout << "\n";
    }
}
