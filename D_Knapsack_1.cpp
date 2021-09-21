
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
template<class Fun> class y_combinator_result {
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define weight first
#define cost second
int64_t n, w;
pair<int64_t, int64_t> a[101];
int64_t dp[109][100009];

int64_t solve2(int64_t k, int64_t sum1) {
    if(k == n) return 0;
    if(dp[k][sum1] != -1) return dp[k][sum1];
    
    int64_t ans;
    if(sum1 + a[k].weight <= w) {
        ans = max(solve2(k + 1, sum1 + a[k].weight) + a[k].cost, solve2(k + 1, sum1));
    } else ans = solve2(k + 1, sum1);

    return dp[k][sum1] = ans;
    
}
void solve(){
    memset(dp, -1, sizeof(dp));
	cin >> n >> w;
    for(int64_t i = 0;i < n; ++i) cin >> a[i].weight >> a[i].cost;
    cout << solve2(0, 0);
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
