
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
int n,q,s,t;
vector<int> adj[200010];
vector<pair<int,int>> inout(200010);
int cur = 1;
bool check[200010];
void dfs2(int node, int parent){
    inout[node].first = cur++;
    for(auto i : adj[node]){
        if(parent == i) continue;
        dfs2(i, node);
    }
    inout[node].second = cur++;
}
void solve(){
    cin >> n >> q;
    vector<int> parent;
    vector<int> vertices;
    vertices.emplace_back(0);
    for(int i=0;i<n;++i){
        cin >> s;
        if(s == 1){
            cin >> t;
            check[t] = 1;
            adj[vertices.back()].emplace_back(t);
            adj[t].emplace_back(vertices.back());
            vertices.emplace_back(t);
        } else vertices.pop_back();
    }
    dfs2(0, 0);
    while(q--){
        cin >> s >> t;
        if(!check[s] || !check[t]) cout << "0\n";
        else if(inout[s].first > inout[t].first && inout[s].second < inout[t].second) {
            //t is ancestor of s
            cout << (inout[s].second - inout[s].first + 1) /2 << "\n";
        } else if(inout[s].first < inout[t].first && inout[s].second > inout[t].second) {
            //s is ancestor of t
            cout << (inout[t].second - inout[t].first + 1) /2 << "\n";
        } else cout << "0\n";
    }


}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}


