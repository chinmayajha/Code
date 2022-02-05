#include "bits/stdc++.h"
using namespace std;

vector<string> a, b;
vector<char> path;
vector<vector<int>> vis;
int n, m;

int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
char dc[4] = {'L', 'R', 'U', 'D'};

bool valid(int ii, int jj) {
    return(!(ii < 0 || jj < 0 || ii >= n || jj >= m || a[ii][jj] == '#' || vis[ii][jj] == 1));
}
signed main() {
    cin >> n >> m;
    a.resize(n);
    vis.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) cin >> a[i];
    b = a;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(a[i][j] == 'A') {
        queue<pair<int, int>> q;
        q.push({i, j});

        while((int) q.size() > 0) {
            auto [x, y] = q.front(); q.pop();
            if(a[x][y] != 'B') {
                for(int k = 0; k < 4; ++k) {
                    if(valid(x + dx[k], y + dy[k])) {
                        q.push({x + dx[k], y + dy[k]});
                        b[x + dx[k]][y + dy[k]] = dc[k], vis[x + dx[k]][y + dy[k]] = 1;
                    }
                }
                continue;
            }
            while(true) {
                path.push_back(b[x][y]);
                if(path.back() == 'L') y++;
                if(path.back() == 'R') y--;
                if(path.back() == 'U') x++;
                if(path.back() == 'D') x--;
                if(x == i && y == j) break;
            }
            cout << "YES\n";
            cout << (int) path.size() << "\n";
            while((int) path.size() > 0) {
                cout << path.back();
                path.pop_back();
            }
            exit(0);    
        }
        cout << "NO\n";
    }
    
}
