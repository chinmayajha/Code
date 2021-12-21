
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#ifdef crazybarcafan
#include "debug.hpp"
#else
#define print(...)
#define dbg(...)
#endif



void solve(){
    vector<int> adj[100010];
    int n, k, p, q;
    vector<int> vis(100010, 0);

    cin >> n >> k;
    for(int i = 0; i < k; ++i) {
        cin >> p; vis[p] = INT_MAX;
    }

    for(int i = 0; i < n - 1; ++i) {
        cin >> p >> q;
        adj[p].push_back(q); adj[q].push_back(p);
    }

    bool check = 0;

    // search
    int cur;
    queue<int> qq;
    qq.push(1);
    vis[1] = 1;
    while(!qq.empty()) {
        cur = qq.front();
        qq.pop();
        if(sz(adj[cur]) == 1 && vis[adj[cur][0]] != INT_MAX) {
            check = 1;
            break;
        }
        for(auto& i : adj[cur]) {
            if(vis[i] == 0) {
                qq.push(i);
                vis[i] = 1;
            }
        }
    }

    if(!check) {
        if(sz(adj[cur]) == 1 && vis[adj[cur][0]] != INT_MAX) {
            check = 1;
        } else if(sz(adj[cur]) >= 1 && qq.empty()) check = 0;
    }
     cout << (check ? "YES\n" : "NO\n");
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

