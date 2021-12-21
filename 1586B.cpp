
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
template<class Fun> class y_combinator_result {
    #define endl '\n'
    Fun fun_;
    public:
        template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
        template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename TT, typename... UU> void dbg_out(TT H, UU... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
int p,q,r;
vector<int> ans;
vector<int> adj[int(1e5+10)];
vector<int> vis(int(1e5 + 10));
set<pair<int, int>> x;
void dfs(int k, int parent) {
    vis[k] = 1;
    for(auto& i : adj[k]) {
        if(i == parent) continue;
        if(!vis[i]) dfs(i, k);
    }
}
void solve(){
    vis.clear();
    ans.clear();
    x.clear();
    for(int k = 0; k < int(1e5+10); ++k) {
        adj[k].clear();
    }
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> p >> q >> r;
        adj[p].emplace_back(r);
    }
    for(int i = 1; i <= n; ++i) {
        if(vis[i]) continue;
        ans.emplace_back(i);
        dfs(i, -1);
    }
    for(int i = 0; i < sz(ans) - 1; ++i) {
        adj[ans[i + 1]].emplace_back(ans[i]);
    }
    for(int i = 0; i < int(1e5+10); ++i) {
        for(auto& j : adj[i]) x.insert(make_pair(i, j));
    }
    for(auto& i : x) cout << i.first << " " << i.second << "\n";
    cout << "sfvev\n";
    
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
