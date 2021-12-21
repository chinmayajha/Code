
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
#include "debug.hpp"
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define print(...)
#define dbg(...)
#endif 

const int mx = 2e5 + 10;

int64_t n, a, b;
vector<pair<int64_t, int64_t>> adj[mx];
int64_t dist[mx][2];

void dfs(int64_t node, int64_t parent, int64_t check) {
    for(auto& i : adj[node]) {
        if(i.first == parent) continue;
        dist[i.first][check] = dist[node][check] + i.second;
        dfs(i.first, node, check);
    }
}

void solve(){
    cin >> n >> a >> b;
    for(int64_t i = 0; i < n - 1; ++i) {
        int64_t x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    dfs(a, -1, 0);
    dfs(b, -1, 1);
    
    vector<pair<int64_t, int64_t>> ans;
    for(int64_t i = 1; i <= n; ++i) {
        ans.push_back({dist[i][0] + dist[i][1], dist[i][0]});
    }
    sort(ans.rbegin(), ans.rend());
    int64_t cnt = 0;
    for(int64_t i = 0; i < sz(ans); ++i) {
        if(i % 2) cnt -= (ans[i].first - ans[i].second);
        else cnt += ans[i].second;
    }

    cout << cnt;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
