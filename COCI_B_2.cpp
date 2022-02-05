#include <bits/stdc++.h>
using namespace std;
const int INF = 1e18;
#define int long long

int n, m, x, y, z, k, q;

struct edge {
    int start, end, weight;
};
vector<edge> e;

int bellman_ford() {
    cin >> x >> y;
    int u, v, weight, i, j = 0;
    vector<int> dis(n + 1, INF), far(n + 1, n + 1);
    
	dis[x] = 0;
    far[x] = 0;

    for (i = 1; i <= n - 1; i++) {
		bool check = 1;
        for (j = 0; j < m; j++) {
            u = e[j].start;
            v = e[j].end;
            weight = e[j].weight;

            if (dis[u] != INF && dis[u] + weight < dis[v] && far[u] + 1 <= k) {
                dis[v] = dis[u] + weight;
				far[v] = far[u] + 1;
				check = 0;
            }
        }
		if(check) break;
    }
    
    return (dis[y] == INF ? -1 : dis[y]);

}

signed main() {
    cin >> n >> m;
    e.resize(m);
    for(int i = 0; i < m; ++i) {
        cin >> e[i].start >> e[i].end >> e[i].weight; 
    }

    cin >> k >> q;
    for(int i = 0; i < q; ++i) cout << bellman_ford() << "\n";
}
