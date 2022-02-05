// https://codebreaker.xyz/problem/pokemonmaster 
#include "bits/stdc++.h"
using namespace std;
#define int long long

int r, c, q;
vector<vector<int>> l, p;
set<int> s, z;
bool valid(int power, int i, int j) {
    return (i >= 1 && j >= 1 && i <= r && j <= c && l[i][j] <= power);
}

void dfs(int x, int y, int power, vector<vector<bool>>& vis) {
    vis[x][y] = 1;
    if(valid(power, x, y)) s.insert(p[x][y]);
    else return;
    if(valid(power, x + 1, y) && !vis[x + 1][y]) dfs(x + 1, y, power, vis);
    if(valid(power, x, y + 1) && !vis[x][y + 1]) dfs(x, y + 1, power, vis);
    if(valid(power, x - 1, y) && !vis[x - 1][y]) dfs(x - 1, y, power, vis);
    if(valid(power, x, y - 1) && !vis[x][y - 1]) dfs(x, y - 1, power, vis);
}

void preprocess() {
    // subtask 4
    if(r == 1 && q > 10 && q <= 100000) {
        while(q--) {
            int t, x, y, a;
            cin >> t >> y >> x >> a;
            if(t == 1) p[x][y] = a;
            else {
                
            }
        }
    }
    // subtask 1 and 2 DONE
    l.assign(r + 1, vector<int>(c + 1, 0));
    p.assign(r + 1, vector<int>(c + 1, 0));
    for(int i = 1; i <= r; ++i) for(int j = 1; j <= c; ++j) cin >> l[i][j];
    for(int i = 1; i <= r; ++i) for(int j = 1; j <= c; ++j) cin >> p[i][j];
    //
    while(q--) {
        int t, x, y, a;
        cin >> t >> y >> x >> a;
        if(t == 1) p[x][y] = a;
        else {
            vector<vector<bool>> vis(r + 1, vector<bool>(c + 1, 0));
            dfs(x, y, a, vis);
            cout << (int) s.size() << "\n";
            s.clear();
        }
    }
}

signed main() {
    cin >> r >> c >> q;
    preprocess();
}