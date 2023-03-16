#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int dist[MAXN];

int bfs(int start) {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthestNode = start, maxDist = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                if (dist[v] > maxDist) {
                    maxDist = dist[v];
                    farthestNode = v;
                }
                q.push(v);
            }
        }
    }
    return farthestNode;
}

int diameter(int root, int n) {
    int u = bfs(root);
    int v = bfs(u);
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : adj[x]) {
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    q.push(v);
    dist[v] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : adj[x]) {
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }
    int diameter = 0;
    for (int w = 1; w <= n; w++) {
        if (dist[w] != -1) {
            diameter = max(diameter, dist[w]);
        }
    }
    return diameter;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        for(int i = 1; i <= n; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cout << diameter(1, n) << " ";
        }
        cout << "\n";
    }
    return 0;
}
