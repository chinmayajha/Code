
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
const int64_t mx = 1e5 + 10;
int64_t link[mx], siz[mx], sum[mx];

void init() {
    for(int64_t i = 1; i < mx; ++i) link[i] = i;
}

int64_t find(int64_t x) {
    while(x != link[x]) x = link[x];
    return x;
}

bool same(int64_t x, int64_t y) {
    return (find(x) == find(y));
}

void unite(int64_t x, int64_t y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    link[y] = x;
    //implementation over ^^

    sum[x] += sum[y];

}

void solve(){
    int64_t n; cin >> n;
    vector<int64_t> a(n), b(n), ans(n);
    for(int64_t i = 0; i < n; ++i) cin >> a[i];
    for(int64_t i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    init();

    int64_t cur = 0;
    for(int64_t i = n - 1; i >= 0; i--) {
        ans[i] = cur;
        siz[b[i]] = 1;
        sum[b[i]] = a[b[i]];
        if(b[i] > 0 && siz[b[i] - 1] > 0) unite(b[i] - 1, b[i]);
        if(b[i] < n - 1 && siz[b[i] + 1] > 0) unite(b[i] + 1, b[i]);
        
        cur = max(cur, sum[find(b[i])]);
    }

    for(auto& i : ans) {cout << i << "\n";}
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
