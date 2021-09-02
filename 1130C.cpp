
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
int n,c1,d1,c2,d2;
bool vis[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string a[51];
set<pair<int, int>> s, t;
bool valid(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < n && a[x][y] == '0')  return 1;
    return 0;
}
void dfs(int x, int y) {
    vis[x][y] = 1;
    s.insert(make_pair(x,y));
    for(int i = 0;i < 4; ++i) {
        if(!vis[x + dx[i]][y + dy[i]] && valid(x + dx[i],y + dy[i])) {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}
void dfs2(int x, int y) {
    vis[x][y] = 1;
    t.insert(make_pair(x,y));
    for(int i = 0;i < 4; ++i) {
        if(!vis[x + dx[i]][y + dy[i]] && valid(x + dx[i],y + dy[i])) {
            dfs2(x + dx[i], y + dy[i]);
        }
    }
}
int dist(int x1, int x2, int y1, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
void solve(){
	cin >> n;
    cin >> c1 >> d1;
    cin >> c2 >> d2;
    c1--; d1--; c2--; d2--;
    inarr(a,n);
    dfs(c1,d1);
    dfs2(c2, d2);
    if(s == t) {
        cout << 0;
        return;
    }
    int mx = INT_MAX;
    for(auto& i : s) for(auto& j : t) {
        mx = min(mx, dist(i.first, j.first, i.second, j.second));
    }
    cout << mx;
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

