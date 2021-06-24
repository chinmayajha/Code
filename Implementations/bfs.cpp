#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, p, q, x, y;
bool adj[1001][1001];
bool vis[1001];
deque<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while (m--) {
        cin >> x >> y;
        adj[x][y] = adj[y][x] = true;
    }
    int bfs_ele = 1;
    st.push_back(bfs_ele);
    vis[bfs_ele] = true;
    while (!st.empty()) {
        x = st.front();
        st.pop_front();
        cout << x << "\n";
        for (int i = 1; i <= n; ++i)
            if (!vis[i] && adj[x][i]) {
                st.push_back(i);
                vis[i] = true;
            }
    }

    return 0;
}