
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
const int N = 2e5 + 10;
vector<int> adj[N];
int n, p, q, mx_distance, mx_node1 = -1, mx_node2 = -1;

void dfs(int node, int parent, int dist, bool secondtime = 0) {
    if(dist > mx_distance) {
        if(secondtime) mx_node2 = node;
        else mx_node1 = node;
        mx_distance = dist;
    }
    for(auto& i : adj[node]) {
        if(i == parent) continue;
        dfs(i, node, dist + 1, secondtime);
    }
} 

int heights1[N], heights2[N];
void bfs(bool secondtime = 0) {
    queue<int> qq;
    qq.push(secondtime ? mx_node2 : mx_node1);
    qq.push(-1);
    vector<bool> vis(n + 1, 0);
    int h = 0;
    while(sz(qq) > 1) {
        int cur = qq.front();
        qq.pop();
        if(cur == -1) {
            h++;
            qq.push(-1);
            continue;
        }
        vis[cur] = 1;
        if(!secondtime) heights1[cur] = h;
        else heights2[cur] = h;
        for(auto& i : adj[cur]) {
            if(!vis[i]) qq.push(i);
        }
    }
}

void solve() {
    cin >> n;
    if(n == 1) {
        cout << 0;
        return;
    }
    for(int i = 0; i < n; ++i) {
        cin >> p >> q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    dfs(1, -1, 1, 0); //find one end of diameter
    mx_distance = 0;
    dfs(mx_node1, -1, 0, 1); // find another end of diameter

    bfs(0); //calculate height from 1 end of diameter
    bfs(1); //calculate height from another end of diameter
    
    for(int i = 1; i <= n; ++i) cout << max(heights1[i], heights2[i]) << " ";
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
